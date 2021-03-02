class Solution:
  def ways(self, pizza: List[str], k: int) -> int:
    M = len(pizza)
    N = len(pizza[0])

    prefix = [[0] * (N + 1) for _ in range(M + 1)]

    for i in range(M):
      for j in range(N):
        prefix[i + 1][j + 1] = (pizza[i][j] == 'A') + \
            prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j]

    def hasApple(row1: int, row2: int, col1: int, col2: int) -> bool:
      return (prefix[row2][col2] - prefix[row1][col2] -
              prefix[row2][col1] + prefix[row1][col1]) > 0

    @lru_cache(None)
    def ways(m: int, n: int, k: int) -> int:
      if k == 0:
        return 1

      ans = 0

      for i in range(m + 1, M):
        if hasApple(m, i, n, N) and hasApple(i, M, n, N):
          ans += ways(i, n, k - 1)

      for j in range(n + 1, N):
        if hasApple(m, M, n, j) and hasApple(m, M, j, N):
          ans += ways(m, j, k - 1)

      return ans

    return ways(0, 0, k - 1) % (10**9 + 7)
