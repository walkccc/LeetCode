class Solution {
  public int[] rowAndMaximumOnes(int[][] mat) {
    int[] ans = new int[2];

    for (int i = 0; i < mat.length; ++i) {
      final int ones = (int) Arrays.stream(mat[i]).filter(a -> a == 1).count();
      if (ones > ans[1]) {
        ans[0] = i;
        ans[1] = ones;
      }
    }

    return ans;
  }
}
