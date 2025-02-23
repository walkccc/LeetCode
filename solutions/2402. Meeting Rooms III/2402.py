class Solution:
  def mostBooked(self, n: int, meetings: list[list[int]]) -> int:
    count = [0] * n

    meetings.sort()

    occupied = []  # (endTime, roomId)
    availableRoomIds = [i for i in range(n)]
    heapq.heapify(availableRoomIds)

    for start, end in meetings:
      # Push meetings ending before this `meeting` in occupied to the
      # `availableRoomsIds`.
      while occupied and occupied[0][0] <= start:
        heapq.heappush(availableRoomIds, heapq.heappop(occupied)[1])
      if availableRoomIds:
        roomId = heapq.heappop(availableRoomIds)
        count[roomId] += 1
        heapq.heappush(occupied, (end, roomId))
      else:
        newStart, roomId = heapq.heappop(occupied)
        count[roomId] += 1
        heapq.heappush(occupied, (newStart + (end - start), roomId))

    return count.index(max(count))
