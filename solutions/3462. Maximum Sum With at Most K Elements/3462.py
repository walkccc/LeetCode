class Solution:
  def maxSum(self, grid: list[list[int]], limits: list[int], k: int) -> int:
    minHeap = []

    for row, limit in zip(grid, limits):
      row.sort(reverse=True)
      for i in range(limit):
        heapq.heappush(minHeap, row[i])
        if len(minHeap) == k + 1:
          heapq.heappop(minHeap)

    return sum(minHeap)
