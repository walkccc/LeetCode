class Solution:
  def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
    ans = 0
    i = 0  # station's index
    curr = startFuel
    maxHeap = []

    while curr < target:
      # Add all the reachable stops to maxHeap
      while i < len(stations) and stations[i][0] <= curr:
        heapq.heappush(maxHeap, -stations[i][1])
        i += 1
      if not maxHeap:  # Can't be refueled.
        return -1
      curr -= heapq.heappop(maxHeap)  # Pop out the largest gas.
      ans += 1  # Then, refuel once.

    return ans
