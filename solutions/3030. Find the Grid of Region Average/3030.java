class Solution {
  public int[][] resultGrid(int[][] image, int threshold) {
    final int m = image.length;
    final int n = image[0].length;
    int[][] sums = new int[m][n];
    int[][] counts = new int[m][n];

    for (int i = 0; i < m - 2; ++i)
      for (int j = 0; j < n - 2; ++j)
        if (isRegion(image, i, j, threshold)) {
          final int subgridSum = getSubgridSum(image, i, j);
          for (int x = i; x < i + 3; ++x)
            for (int y = j; y < j + 3; ++y) {
              sums[x][y] += subgridSum / 9;
              counts[x][y] += 1;
            }
        }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (counts[i][j] > 0)
          image[i][j] = sums[i][j] / counts[i][j];

    return image;
  }

  // Returns true if image[i..i + 2][j..j + 2] is a region.
  private boolean isRegion(int[][] image, int i, int j, int threshold) {
    for (int x = i; x < i + 3; ++x)
      for (int y = j; y < j + 3; ++y) {
        if (x > i && Math.abs(image[x][y] - image[x - 1][y]) > threshold)
          return false;
        if (y > j && Math.abs(image[x][y] - image[x][y - 1]) > threshold)
          return false;
      }
    return true;
  }

  // Returns the sum of image[i..i + 2][j..j + 2].
  private int getSubgridSum(int[][] image, int i, int j) {
    int subgridSum = 0;
    for (int x = i; x < i + 3; ++x)
      for (int y = j; y < j + 3; ++y)
        subgridSum += image[x][y];
    return subgridSum;
  }
}
