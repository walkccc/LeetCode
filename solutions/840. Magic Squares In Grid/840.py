class Solution:
  def numMagicSquaresInside(self, grid: list[list[int]]) -> int:
    def isMagic(i: int, j: int) -> int:
      s = "".join(str(grid[i + num // 3][j + num % 3])
                  for num in [0, 1, 2, 5, 8, 7, 6, 3])
      return s in "43816729" * 2 or s in "43816729"[::-1] * 2

    ans = 0

    for i in range(len(grid) - 2):
      for j in range(len(grid[0]) - 2):
        if grid[i][j] % 2 == 0 and grid[i + 1][j + 1] == 5:
          ans += isMagic(i, j)

    return ans
