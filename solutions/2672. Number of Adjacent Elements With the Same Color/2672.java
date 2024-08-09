class Solution {
  public int[] colorTheArray(int n, int[][] queries) {
    int[] ans = new int[queries.length];
    int[] arr = new int[n];
    int sameColors = 0;

    for (int i = 0; i < queries.length; ++i) {
      final int j = queries[i][0];
      final int color = queries[i][1];
      if (j + 1 < n) {
        if (arr[j + 1] > 0 && arr[j + 1] == arr[j])
          --sameColors;
        if (arr[j + 1] == color)
          ++sameColors;
      }
      if (j > 0) {
        if (arr[j - 1] > 0 && arr[j - 1] == arr[j])
          --sameColors;
        if (arr[j - 1] == color)
          ++sameColors;
      }
      arr[j] = color;
      ans[i] = sameColors;
    }

    return ans;
  }
}
