class Solution:
  def allCellsDistOrder(self, rows: int, cols: int, rCenter: int, cCenter: int) -> List[List[int]]:
    dirs = [0, 1, 0, -1, 0]
    ans = []
    q = collections.deque([(rCenter, cCenter)])
    seen = {(rCenter, cCenter)}

    while q:
      i, j = q.popleft()
      ans.append([i, j])
      for k in range(4):
        x = i + dirs[k]
        y = j + dirs[k + 1]
        if x < 0 or x == rows or y < 0 or y == cols:
          continue
        if (x, y) in seen:
          continue
        seen.add((x, y))
        q.append((x, y))

    return ans
