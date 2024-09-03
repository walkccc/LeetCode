class Solution:
  def minArea(self, image: list[list[str]], x: int, y: int) -> int:
    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))
    m = len(image)
    n = len(image[0])
    topLeft = [x, y]
    bottomRight = [x, y]
    q = collections.deque([(x, y)])
    image[x][y] = '2'  # Mark as visited.

    while q:
      i, j = q.popleft()
      for dx, dy in dirs:
        r = i + dx
        c = j + dy
        if r < 0 or r == m or c < 0 or c == n:
          continue
        if image[r][c] != '1':
          continue
        topLeft[0] = min(topLeft[0], r)
        topLeft[1] = min(topLeft[1], c)
        bottomRight[0] = max(bottomRight[0], r)
        bottomRight[1] = max(bottomRight[1], c)
        q.append((r, c))
        image[r][c] = '2'

    width = bottomRight[1] - topLeft[1] + 1
    height = bottomRight[0] - topLeft[0] + 1
    return width * height
