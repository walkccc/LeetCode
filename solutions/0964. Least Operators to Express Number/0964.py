class Solution:
  def leastOpsExpressTarget(self, x: int, target: int) -> int:
    @functools.lru_cache(None)
    def dfs(target):
      if x > target:
        return min(2 * target - 1, 2 * (x - target))
      if x == target:
        return 0

      prod = x
      n = 0
      while prod < target:
        prod *= x
        n += 1
      if prod == target:
        return n

      ans = dfs(target - prod // x) + n
      if prod < 2 * target:
        ans = min(ans, dfs(prod - target) + n + 1)
      return ans

    return dfs(target)
