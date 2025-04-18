class Solution:
  def numberOfPatterns(self, m: int, n: int) -> int:
    seen = set()
    accross = [[0] * 10 for _ in range(10)]

    accross[1][3] = accross[3][1] = 2
    accross[1][7] = accross[7][1] = 4
    accross[3][9] = accross[9][3] = 6
    accross[7][9] = accross[9][7] = 8
    accross[1][9] = accross[9][1] = accross[2][8] = accross[8][2] = \
        accross[3][7] = accross[7][3] = accross[4][6] = accross[6][4] = 5

    def dfs(u: int, depth: int) -> int:
      if depth > n:
        return 0

      seen.add(u)
      ans = 1 if depth >= m else 0

      for v in range(1, 10):
        if v == u or v in seen:
          continue
        accrossed = accross[u][v]
        if not accrossed or accrossed in seen:
          ans += dfs(v, depth + 1)

      seen.remove(u)
      return ans

    # 1, 3, 7, 9 are symmetric
    # 2, 4, 6, 8 are symmetric
    return dfs(1, 1) * 4 + dfs(2, 1) * 4 + dfs(5, 1)
