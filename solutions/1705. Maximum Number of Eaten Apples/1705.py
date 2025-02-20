class Solution:
  def eatenApples(self, apples: list[int], days: list[int]) -> int:
    n = len(apples)
    ans = 0
    minHeap = []  # (the rotten day, the number of apples)

    i = 0
    while i < n or minHeap:
      # Remove the rotten apples.
      while minHeap and minHeap[0][0] <= i:
        heapq.heappop(minHeap)
      # Add today's apples.
      if i < n and apples[i] > 0:
        heapq.heappush(minHeap, (i + days[i], apples[i]))
      # Eat one apple today.
      if minHeap:
        rottenDay, numApples = heapq.heappop(minHeap)
        if numApples > 1:
          heapq.heappush(minHeap, (rottenDay, numApples - 1))
        ans += 1
      i += 1

    return ans
