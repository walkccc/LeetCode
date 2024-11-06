class Solution:
  def findFarmland(self, land: list[list[int]]) -> list[list[int]]:
    ans = []

    def dfs(i: int, j: int, cell: list[int]) -> None:
      if i < 0 or i == len(land) or j < 0 or j == len(land[0]):
        return
      if land[i][j] != 1:
        return
      land[i][j] = 2  # Mark as visited.
      cell[0] = max(cell[0], i)
      cell[1] = max(cell[1], j)
      dfs(i + 1, j, cell)
      dfs(i, j + 1, cell)

    for i in range(len(land)):
      for j in range(len(land[0])):
        if land[i][j] == 1:
          cell = [i, j]
          dfs(i, j, cell)
          ans.append([i, j, *cell])

    return ans
