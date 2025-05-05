class Solution:
  def minFlips(self, grid: list[list[int]]) -> int:
    m = len(grid)
    n = len(grid[0])
    ans = 0
    middleOnes = 0
    mismatchedPairs = 0

    # Handle top-left, top-right, bottom-left, bottom-right cells.
    for i in range(m // 2):
      for j in range(n // 2):
        ones = (grid[i][j] + grid[i][n - 1 - j] +
                grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j])
        ans += min(ones, 4 - ones)

    # Handle the middle row if the number of m is odd.
    if m % 2 == 1:
      for j in range(n // 2):
        leftCell = grid[m // 2][j]
        rightCell = grid[m // 2][n - 1 - j]
        mismatchedPairs += leftCell ^ rightCell
        middleOnes += leftCell + rightCell

    # Handle the middle column if the number of columns is odd.
    if n % 2 == 1:
      for i in range(m // 2):
        topCell = grid[i][n // 2]
        bottomCell = grid[m - 1 - i][n // 2]
        mismatchedPairs += topCell ^ bottomCell
        middleOnes += topCell + bottomCell

    if mismatchedPairs == 0:
      # Since there's no mismatched pairs, middleOnes % 4 must be 0 or 2.
      if middleOnes % 4 == 2:
        ans += 2  # Flip two 1s to 0s.
    else:
      # Flip every mismatched pair 01 to 00 or 11. It doesn't matter.
      ans += mismatchedPairs

    # Handle the center cell if both dimensions are odd.
    if m % 2 == 1 and n % 2 == 1:
      ans += grid[m // 2][n // 2]

    return ans
