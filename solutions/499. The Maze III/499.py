class Solution:
  def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
    ans = "impossible"
    minSteps = math.inf

    def dfs(i: int, j: int, dx: int, dy: int, steps: int, path: str):
      nonlocal ans
      nonlocal minSteps
      if steps >= minSteps:
        return

      if dx != 0 or dy != 0:  # Both are zeros for the initial ball position.
        while 0 <= i + dx < len(maze) and 0 <= j + dy < len(maze[0]) \
                and maze[i + dx][j + dy] != 1:
          i += dx
          j += dy
          steps += 1
          if i == hole[0] and j == hole[1] and steps < minSteps:
            minSteps = steps
            ans = path

      if maze[i][j] == 0 or steps + 2 < maze[i][j]:
        maze[i][j] = steps + 2  # +2 because maze[i][j] == 0 || 1.
        if dx == 0:
          dfs(i, j, 1, 0, steps, path + 'd')
        if dy == 0:
          dfs(i, j, 0, -1, steps, path + 'l')
        if dy == 0:
          dfs(i, j, 0, 1, steps, path + 'r')
        if dx == 0:
          dfs(i, j, -1, 0, steps, path + 'u')

    dfs(ball[0], ball[1], 0, 0, 0, '')
    return ans
