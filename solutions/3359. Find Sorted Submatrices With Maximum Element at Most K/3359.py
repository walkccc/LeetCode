from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  subarrayWidth: int
  rowIndex: int
  accumulatedSubmatrices: int


class Solution:
  def countSubmatrices(self, grid: list[list[int]], k: int) -> int:
    m = len(grid)
    n = len(grid[0])
    ans = 0
    # dp[i][j] := the number of valid subarrays ending in grid[i][j]
    dp = [[0] * n for _ in range(m)]
    # stacks[j] := the stack of valid
    # (subarray width, row index, number of accumulated submatrices) ending in
    # column j
    stacks: list[T] = [[T(0, -1, 0)] for _ in range(n)]

    for i, row in enumerate(grid):
      for j, num in enumerate(row):
        if num > k:
          stacks[j] = [T(0, i, 0)]
        else:
          dp[i][j] = 1
          if j > 0 and row[j - 1] <= k and row[j - 1] >= row[j]:
            # Extend the valid subarrays to the current number.
            dp[i][j] += dp[i][j - 1]
          width = dp[i][j]
          # Remove subarray widths greater than the current count since they
          # will become invalid.
          while stacks[j] and width < stacks[j][-1].subarrayWidth:
            stacks[j].pop()
          height = i - stacks[j][-1].rowIndex
          newSubmatrices = width * height
          accumulatedSubmatrices = (stacks[j][-1].accumulatedSubmatrices +
                                    newSubmatrices)
          ans += accumulatedSubmatrices
          stacks[j].append(T(width, i, accumulatedSubmatrices))

    return ans
