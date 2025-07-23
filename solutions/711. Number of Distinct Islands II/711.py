class Solution:
  def numDistinctIslands2(self, grid: list[list[int]]) -> int:
    seen = set()

    def dfs(i: int, j: int):
      if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]):
        return
      if grid[i][j] == 0 or (i, j) in seen:
        return

      seen.add((i, j))
      island.append((i, j))
      dfs(i + 1, j)
      dfs(i - 1, j)
      dfs(i, j + 1)
      dfs(i, j - 1)

    def normalize(island: list[tuple]) -> list[tuple]:
      # points[i] := 8 different rotations/reflections of an island
      points = [[] for _ in range(8)]

      for i, j in island:
        points[0].append((i, j))
        points[1].append((i, -j))
        points[2].append((-i, j))
        points[3].append((-i, -j))
        points[4].append((j, i))
        points[5].append((j, -i))
        points[6].append((-j, i))
        points[7].append((-j, -i))

      points = [sorted(p) for p in points]

      # Normalize each p by substracting p[1..7] with p[0].
      for p in points:
        for i in range(1, len(island)):
          p[i] = (p[i][0] - p[0][0],
                  p[i][1] - p[0][1])
        p[0] = (0, 0)

      return sorted(points)[0]

    islands = set()  # all the islands with different shapes

    for i in range(len(grid)):
      for j in range(len(grid[0])):
        island = []
        dfs(i, j)
        if island:
          islands.add(frozenset(normalize(island)))

    return len(islands)
