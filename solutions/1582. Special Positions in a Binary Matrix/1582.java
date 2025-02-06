class Solution {
  public int numSpecial(int[][] mat) {
    final int m = mat.length;
    final int n = mat[0].length;
    int ans = 0;
    int[] rowOnes = new int[m];
    int[] colOnes = new int[n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 1) {
          ++rowOnes[i];
          ++colOnes[j];
        }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 1 && rowOnes[i] == 1 && colOnes[j] == 1)
          ++ans;

    return ans;
  }
}
