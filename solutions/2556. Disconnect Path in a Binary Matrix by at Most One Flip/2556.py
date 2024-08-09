class Solution:
  def isPossibleToCutPath(self, grid: List[List[int]]) -> bool:
    # Returns True is there's a path from (0, 0) to (m - 1, n - 1).
    # Also marks the visited path as 0 except (m - 1, n - 1).
    def hasPath(i: int, j: int) -> bool:
      if i == len(grid) or j == len(grid[0]):
        return False
      if i == len(grid) - 1 and j == len(grid[0]) - 1:
        return True
      if grid[i][j] == 0:
        return False

      grid[i][j] = 0
      # Go down first. Since we use OR logic, we'll only mark one path.
      return hasPath(i + 1, j) or hasPath(i, j + 1)

    if not hasPath(0, 0):
      return True
    # Reassign (0, 0) as 1.
    grid[0][0] = 1
    return not hasPath(0, 0)
