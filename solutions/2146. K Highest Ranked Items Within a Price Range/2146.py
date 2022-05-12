class Solution:
  def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
    m = len(grid)
    n = len(grid[0])
    low, high = pricing
    row, col = start
    dirs = [0, 1, 0, -1, 0]
    ans = []

    if low <= grid[row][col] <= high:
      ans.append([row, col])
      if k == 1:
        return ans

    q = deque([(row, col)])
    seen = {(row, col)}  # mark as visited

    while q:
      neighbors = []
      for _ in range(len(q)):
        i, j = q.popleft()
        for t in range(4):
          x = i + dirs[t]
          y = j + dirs[t + 1]
          if x < 0 or x == m or y < 0 or y == n:
            continue
          if not grid[x][y] or (x, y) in seen:
            continue
          if low <= grid[x][y] <= high:
            neighbors.append([x, y])
          q.append((x, y))
          seen.add((x, y))
      neighbors.sort(key=lambda x: (grid[x[0]][x[1]], x[0], x[1]))
      for neighbor in neighbors:
        if len(ans) < k:
          ans.append(neighbor)
        if len(ans) == k:
          return ans

    return ans
