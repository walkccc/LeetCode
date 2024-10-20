class Solution {
  public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
    if (upper + lower != Arrays.stream(colsum).sum())
      return new ArrayList<>();

    int count = 0;
    for (int c : colsum)
      if (c == 2)
        ++count;

    if (Math.min(upper, lower) < count)
      return new ArrayList<>();

    int[][] ans = new int[2][colsum.length];

    for (int j = 0; j < colsum.length; ++j)
      if (colsum[j] == 2) {
        ans[0][j] = 1;
        ans[1][j] = 1;
        --upper;
        --lower;
      }

    for (int j = 0; j < colsum.length; ++j) {
      if (colsum[j] == 1 && upper > 0) {
        ans[0][j] = 1;
        --colsum[j];
        --upper;
      }

      if (colsum[j] == 1 && lower > 0) {
        ans[1][j] = 1;
        --lower;
      }
    }

    return new ArrayList(Arrays.asList(ans[0], ans[1]));
  }
}
