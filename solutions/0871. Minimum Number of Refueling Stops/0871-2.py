class Solution:
  def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
    ans = 0
    i = 0  # station's index
    curr = startFuel
    maxHeap = []

    while curr < target:
      # add all reachable stops to maxHeap
      while i < len(stations) and stations[i][0] <= curr:
        heapq.heappush(maxHeap, -stations[i][1])
        i += 1
      if not maxHeap:  # we can't refuel
        return -1
      curr -= heapq.heappop(maxHeap)  # pop out the largest gas
      ans += 1  # then refuel once

    return ans
