class Solution:
  def tourOfKnight(self, m: int, n: int, r: int, c: int) -> list[list[int]]:
    dirs = ((1, 2), (2, 1), (2, -1), (1, -2),
            (-1, -2), (-2, -1), (-2, 1), (-1, 2))
    ans = [[-1] * n for _ in range(m)]

    def dfs(i: int, j: int, step: int) -> bool:
      if step == m * n:
        return True
      if i < 0 or i >= m or j < 0 or j >= n:
        return False
      if ans[i][j] != -1:
        return False
      ans[i][j] = step
      for dx, dy in dirs:
        if dfs(i + dx, j + dy, step + 1):
          return True
      ans[i][j] = -1
      return False

    dfs(r, c, 0)
    return ans
