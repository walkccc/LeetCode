class Solution:
  def minIncrements(self, n: int, cost: list[int]) -> int:
    ans = 0

    for i in range(n // 2 - 1, -1, -1):
      l = i * 2 + 1
      r = i * 2 + 2
      ans += abs(cost[l] - cost[r])
      # Record the information in the parent from the children. So, there's need to actually
      # update the values in the children.
      cost[i] += max(cost[l], cost[r])

    return ans
