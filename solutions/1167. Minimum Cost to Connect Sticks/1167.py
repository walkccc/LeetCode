class Solution:
  def connectSticks(self, sticks: list[int]) -> int:
    ans = 0
    heapq.heapify(sticks)

    while len(sticks) > 1:
      x = heapq.heappop(sticks)
      y = heapq.heappop(sticks)
      ans += x + y
      heapq.heappush(sticks, x + y)

    return ans
