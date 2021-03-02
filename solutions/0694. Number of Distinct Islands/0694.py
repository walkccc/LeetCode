class Solution:
  def numDistinctIslands(self, grid: List[List[int]]) -> int:
    seen = set()

    def dfs(i: int, j: int, i0: int, j0: int):
      if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]):
        return
      if grid[i][j] == 0 or (i, j) in seen:
        return

      seen.add((i, j))
      island.append((i - i0, j - j0))
      dfs(i + 1, j, i0, j0)
      dfs(i - 1, j, i0, j0)
      dfs(i, j + 1, i0, j0)
      dfs(i, j - 1, i0, j0)

    islands = set()  # all different islands

    for i in range(len(grid)):
      for j in range(len(grid[0])):
        island = []
        dfs(i, j, i, j)
        if island:
          islands.add(frozenset(island))

    return len(islands)
