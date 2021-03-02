class Solution:
  def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
    ans = 0
    i = 0  # station's index
    curr = startFuel
    pq = []

    while curr < target:
      # add all reachable stops to pq
      while i < len(stations) and stations[i][0] <= curr:
        heapq.heappush(pq, -stations[i][1])
        i += 1
      if not pq:  # we can't refuel
        return -1
      curr += -heapq.heappop(pq)  # pop out the largest gas
      ans += 1  # then refuel once

    return ans
