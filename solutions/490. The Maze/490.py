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
    q = collections.deque([(start[0], start[1])])
    seen = {(start[0], start[1])}

    def isValid(x: int, y: int) -> bool:
      return 0 <= x < m and 0 <= y < n and maze[x][y] == 0

    while q:
      i, j = q.popleft()
      for dx, dy in dirs:
        x = i
        y = j
        while isValid(x + dx, y + dy):
          x += dx
          y += dy
        if [x, y] == destination:
          return True
        if (x, y) in seen:
          continue
        q.append((x, y))
        seen.add((x, y))

    return False
