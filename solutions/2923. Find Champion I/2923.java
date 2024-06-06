class Solution {
  public int findChampion(int[][] grid) {
    final int n = grid.length;
    int ans = -1;
    int count = 0;
    int[] inDegrees = new int[n];

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        if (grid[i][j] == 1)
          ++inDegrees[j];
        else
          ++inDegrees[i];
      }

    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0) {
        ++count;
        ans = i;
      }

    return count > 1 ? -1 : ans;
  }
}
