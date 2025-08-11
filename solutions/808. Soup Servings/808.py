class Solution:
  def soupServings(self, n: int) -> float:
    @functools.lru_cache(None)
    def dfs(a: int, b: int) -> float:
      if a <= 0 and b <= 0:
        return 0.5
      if a <= 0:
        return 1.0
      if b <= 0:
        return 0.0
      return 0.25 * (dfs(a - 4, b) +
                     dfs(a - 3, b - 1) +
                     dfs(a - 2, b - 2) +
                     dfs(a - 1, b - 3))

    return 1 if n >= 4800 else dfs((n + 24) // 25, (n + 24) // 25)
