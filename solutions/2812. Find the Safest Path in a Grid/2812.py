class Solution:
  def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
    self.dirs = [0, 1, 0, -1, 0]
    n = len(grid)
    distToThief = self._getDistToThief(grid)

    def hasValidPath(safeness: int) -> bool:
      if distToThief[0][0] < safeness:
        return False

      q = collections.deque([(0, 0)])
      seen = {(0, 0)}

      while q:
        i, j = q.popleft()
        if distToThief[i][j] < safeness:
          continue
        if i == n - 1 and j == n - 1:
          return True
        for k in range(4):
          x = i + self.dirs[k]
          y = j + self.dirs[k + 1]
          if x < 0 or x == n or y < 0 or y == n:
            continue
          if (x, y) in seen:
            continue
          q.append((x, y))
          seen.add((x, y))

      return False

    return bisect.bisect_left(range(n * 2), True,
                              key=lambda m: not hasValidPath(m)) - 1

  def _getDistToThief(self, grid: List[List[int]]) -> List[List[int]]:
    n = len(grid)
    distToThief = [[0] * n for _ in range(n)]
    q = collections.deque()
    seen = set()

    for i in range(n):
      for j in range(n):
        if grid[i][j] == 1:
          q.append((i, j))
          seen.add((i, j))

    dist = 0
    while q:
      for _ in range(len(q)):
        i, j = q.popleft()
        distToThief[i][j] = dist
        for k in range(4):
          x = i + self.dirs[k]
          y = j + self.dirs[k + 1]
          if x < 0 or x == n or y < 0 or y == n:
            continue
          if (x, y) in seen:
            continue
          q.append((x, y))
          seen.add((x, y))
      dist += 1

    return distToThief
