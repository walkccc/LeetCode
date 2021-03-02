class Solution:
  def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
    if not matrix:
      return 0

    m = len(matrix)
    n = len(matrix[0])

    ans = 0

    @lru_cache(None)
    def dfs(i: int, j: int, prev: int) -> int:
      if i < 0 or i == len(matrix) or j < 0 or j == len(matrix[0]):
        return 0
      if matrix[i][j] <= prev:
        return 0

      curr = matrix[i][j]
      return 1 + max(dfs(i + 1, j, curr),
                     dfs(i - 1, j, curr),
                     dfs(i, j + 1, curr),
                     dfs(i, j - 1, curr))

    return max(dfs(i, j, -inf)
               for i in range(len(matrix))
               for j in range(len(matrix[0])))
