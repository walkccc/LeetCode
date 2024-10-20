class Solution:
  def maxTrailingZeros(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    # leftPrefix2[i][j] := the number of 2 in grid[i][0..j]
    # leftPrefix5[i][j] := the number of 5 in grid[i][0..j]
    # topPrefix2[i][j] := the number of 2 in grid[0..i][j]
    # topPrefix5[i][j] := the number of 5 in grid[0..i][j]
    leftPrefix2 = [[0] * n for _ in range(m)]
    leftPrefix5 = [[0] * n for _ in range(m)]
    topPrefix2 = [[0] * n for _ in range(m)]
    topPrefix5 = [[0] * n for _ in range(m)]

    def getCount(num: int, factor: int) -> int:
      count = 0
      while num % factor == 0:
        num //= factor
        count += 1
      return count

    for i in range(m):
      for j in range(n):
        leftPrefix2[i][j] = getCount(grid[i][j], 2)
        leftPrefix5[i][j] = getCount(grid[i][j], 5)
        if j:
          leftPrefix2[i][j] += leftPrefix2[i][j - 1]
          leftPrefix5[i][j] += leftPrefix5[i][j - 1]

    for j in range(n):
      for i in range(m):
        topPrefix2[i][j] = getCount(grid[i][j], 2)
        topPrefix5[i][j] = getCount(grid[i][j], 5)
        if i:
          topPrefix2[i][j] += topPrefix2[i - 1][j]
          topPrefix5[i][j] += topPrefix5[i - 1][j]

    ans = 0
    for i in range(m):
      for j in range(n):
        curr2 = getCount(grid[i][j], 2)
        curr5 = getCount(grid[i][j], 5)
        l2 = leftPrefix2[i][j]
        l5 = leftPrefix5[i][j]
        r2 = leftPrefix2[i][n - 1] - (0 if j == 0 else leftPrefix2[i][j - 1])
        r5 = leftPrefix5[i][n - 1] - (0 if j == 0 else leftPrefix5[i][j - 1])
        t2 = topPrefix2[i][j]
        t5 = topPrefix5[i][j]
        d2 = topPrefix2[m - 1][j] - (0 if i == 0 else topPrefix2[i - 1][j])
        d5 = topPrefix5[m - 1][j] - (0 if i == 0 else topPrefix5[i - 1][j])
        ans = max(ans,
                  min(l2 + t2 - curr2, l5 + t5 - curr5),
                  min(r2 + t2 - curr2, r5 + t5 - curr5),
                  min(l2 + d2 - curr2, l5 + d5 - curr5),
                  min(r2 + d2 - curr2, r5 + d5 - curr5))

    return ans
