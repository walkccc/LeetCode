class Solution:
  def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> list[list[int]]:
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    ans = [[rStart, cStart]]
    i = 0

    while len(ans) < rows * cols:
      for _ in range(i // 2 + 1):
        rStart += dy[i % 4]
        cStart += dx[i % 4]
        if 0 <= rStart < rows and 0 <= cStart < cols:
          ans.append([rStart, cStart])
      i += 1

    return ans
