class Solution:
  def minCost(self, nums: List[int], x: int) -> int:
    n = len(nums)
    ans = math.inf
    # minCost[i] := the minimum cost to collect the i-th type
    minCost = [math.inf] * n

    for rotate in range(n):
      for i in range(n):
        minCost[i] = min(minCost[i], nums[(i - rotate + n) % n])
      ans = min(ans, sum(minCost) + rotate * x)

    return ans
