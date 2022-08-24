class Solution:
  def ways(self, pizza: List[str], k: int) -> int:
    M = len(pizza)
    N = len(pizza[0])
    prefix = [[0] * (N + 1) for _ in range(M + 1)]

    for i in range(M):
      for j in range(N):
        prefix[i + 1][j + 1] = (pizza[i][j] == 'A') + \
            prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j]

    # hasApple of pizza[row1..row2)[col1..col2)
    def hasApple(row1: int, row2: int, col1: int, col2: int) -> bool:
      return (prefix[row2][col2] - prefix[row1][col2] -
              prefix[row2][col1] + prefix[row1][col1]) > 0

    # dp(m, n, k) := # of ways to cut pizza[m:M][n:N] w/ k cuts
    @functools.lru_cache(None)
    def dp(m: int, n: int, k: int) -> int:
      if k == 0:
        return 1

      ans = 0

      for i in range(m + 1, M):  # cut horizontally
        if hasApple(m, i, n, N) and hasApple(i, M, n, N):
          ans += dp(i, n, k - 1)

      for j in range(n + 1, N):  # cut vertically
        if hasApple(m, M, n, j) and hasApple(m, M, j, N):
          ans += dp(m, j, k - 1)

      return ans

    return dp(0, 0, k - 1) % (10**9 + 7)
