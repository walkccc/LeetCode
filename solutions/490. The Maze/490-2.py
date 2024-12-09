class Solution:
  def hasPath(
      self,
      maze: list[list[int]],
      start: list[int],
      destination: list[int],
  ) -> bool:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(maze)
    n = len(maze[0])

    seen = set()

    def isValid(x: int, y: int) -> bool:
      return 0 <= x < m and 0 <= y < n and maze[x][y] == 0

    def dfs(i: int, j: int) -> bool:
      if [i, j] == destination:
        return True
      if (i, j) in seen:
        return False

      seen.add((i, j))

      for dx, dy in dirs:
        x = i
        y = j
        while isValid(x + dx, y + dy):
          x += dx
          y += dy
        if dfs(x, y):
          return True

      return False

    return dfs(start[0], start[1])
