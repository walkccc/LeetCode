class Solution {
  public int minFlips(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;
    int middleOnes = 0;
    int mismatchedPairs = 0;

    // Handle top-left, top-right, bottom-left, bottom-right cells.
    for (int i = 0; i < m / 2; ++i) {
      for (int j = 0; j < n / 2; ++j) {
        final int ones =
            grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
        ans += Math.min(ones, 4 - ones);
      }
    }

    // Handle the middle row if the number of m is odd.
    if (m % 2 == 1)
      for (int j = 0; j < n / 2; ++j) {
        final int leftCell = grid[m / 2][j];
        final int rightCell = grid[m / 2][n - 1 - j];
        mismatchedPairs += leftCell ^ rightCell;
        middleOnes += leftCell + rightCell;
      }

    // Handle the middle column if the number of columns is odd.
    if (n % 2 == 1)
      for (int i = 0; i < m / 2; ++i) {
        final int topCell = grid[i][n / 2];
        final int bottomCell = grid[m - 1 - i][n / 2];
        mismatchedPairs += topCell ^ bottomCell;
        middleOnes += topCell + bottomCell;
      }

    if (mismatchedPairs == 0) {
      // Since there's no mismatched pairs, middleOnes % 4 must be 0 or 2.
      if (middleOnes % 4 == 2)
        ans += 2; // Flip two 1s to 0s.
    } else {
      // Flip every mismatched pair 01 to 00 or 11. It doesn't matter.
      ans += mismatchedPairs;
    }

    // Handle the center cell if both dimensions are odd.
    if (m % 2 == 1 && n % 2 == 1)
      ans += grid[m / 2][n / 2];

    return ans;
  }
}
