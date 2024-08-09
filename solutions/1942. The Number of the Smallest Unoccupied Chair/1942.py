class Solution:
  def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
    nextUnsatChair = 0
    emptyChairs = []
    occupied = []  # (leaving, chair)

    for i in range(len(times)):
      times[i].append(i)

    times.sort(key=lambda time: time[0])

    for arrival, leaving, i in times:
      while len(occupied) > 0 and occupied[0][0] <= arrival:
        unsatChair = heapq.heappop(occupied)[1]
        heapq.heappush(emptyChairs, unsatChair)
      if i == targetFriend:
        return emptyChairs[0] if len(emptyChairs) > 0 else nextUnsatChair
      if len(emptyChairs) == 0:
        heapq.heappush(occupied, (leaving, nextUnsatChair))
        nextUnsatChair += 1
      else:
        emptyChair = heapq.heappop(emptyChairs)
        heapq.heappush(occupied, (leaving, emptyChair))
