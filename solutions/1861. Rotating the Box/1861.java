class Solution {
  public char[][] rotateTheBox(char[][] box) {
    final int m = box.length;
    final int n = box[0].length;
    char[][] ans = new char[n][m];
    Arrays.stream(ans).forEach(A -> Arrays.fill(A, '.'));

    for (int i = 0; i < m; ++i)
      for (int j = n - 1, k = n - 1; j >= 0; --j)
        if (box[i][j] != '.') {
          if (box[i][j] == '*')
            k = j;
          ans[k--][m - i - 1] = box[i][j];
        }

    return ans;
  }
}
