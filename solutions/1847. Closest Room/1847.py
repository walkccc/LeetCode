from sortedcontainers import SortedList


class Solution:
  def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
    ans = [0] * len(queries)
    qs = [[*q, i] for i, q in enumerate(queries)]
    roomIds = SortedList()

    rooms.sort(key=lambda x: -x[1])
    qs.sort(key=lambda x: -x[1])

    def searchClosestRoomId(roomIds: SortedList, preferred: int):
      if not roomIds:
        return -1

      candIds = []
      i = roomIds.bisect_right(preferred)
      if i > 0:
        candIds.append(roomIds[i - 1])
      if i < len(roomIds):
        candIds.append(roomIds[i])
      return min(candIds, key=lambda x: abs(x - preferred))

    i = 0  # rooms' pointer
    for preferred, minSize, index in qs:
      while i < len(rooms) and rooms[i][1] >= minSize:
        roomIds.add(rooms[i][0])
        i += 1
      ans[index] = searchClosestRoomId(roomIds, preferred)

    return ans
