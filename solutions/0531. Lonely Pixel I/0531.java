class Solution {
  public int findLonelyPixel(char[][] picture) {
    final int m = picture.length;
    final int n = picture[0].length;

    int ans = 0;
    int[] row = new int[m]; // row[i] := # of Bs in row i
    int[] col = new int[n]; // col[i] := # of Bs in col i

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (picture[i][j] == 'B') {
          ++row[i];
          ++col[j];
        }

    for (int i = 0; i < m; ++i)
      if (row[i] == 1) // only have to examine the row when row[i] == 1
        for (int j = 0; j < n; ++j)
          // after we met the 'B' in this row, we break and search the next row
          if (picture[i][j] == 'B') {
            if (col[j] == 1)
              ++ans;
            break;
          }

    return ans;
  }
}
