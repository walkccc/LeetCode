class Solution:
  def soupServings(self, N: int) -> float:
    def dfs(a: int, b: int) -> float:
      if a <= 0 and b <= 0:
        return 0.5
      if a <= 0:
        return 1.0
      if b <= 0:
        return 0.0
      if memo[a][b] > 0:
        return memo[a][b]

      memo[a][b] = 0.25 * (dfs(a - 4, b) +
                           dfs(a - 3, b - 1) +
                           dfs(a - 2, b - 2) +
                           dfs(a - 1, b - 3))
      return memo[a][b]

    memo = [[0.0] * 192 for _ in range(192)]
    return 1 if N >= 4800 else dfs((N + 24) // 25, (N + 24) // 25)
