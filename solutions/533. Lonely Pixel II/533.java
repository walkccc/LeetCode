class Solution {
  public int findBlackPixel(char[][] picture, int target) {
    final int m = picture.length;
    final int n = picture[0].length;
    int ans = 0;
    int[] rows = new int[m];
    int[] cols = new int[n];
    String[] rowStrings = new String[m];
    Map<String, Integer> countRowStrings = new HashMap<>();

    for (int i = 0; i < m; ++i) {
      StringBuilder sb = new StringBuilder();
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B') {
          ++rows[i];
          ++cols[j];
        }
        sb.append(picture[i][j]);
      }
      rowStrings[i] = sb.toString();
      countRowStrings.merge(rowStrings[i], 1, Integer::sum);
    }

    for (int i = 0; i < m; ++i)
      if (rows[i] == target && countRowStrings.get(rowStrings[i]) == target)
        for (int j = 0; j < n; ++j)
          if (picture[i][j] == 'B' && cols[j] == target)
            ++ans;

    return ans;
  }
}
