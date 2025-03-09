class Solution {
  public int[][] matrixReshape(int[][] nums, int r, int c) {
    if (nums.length == 0 || r * c != nums.length * nums[0].length)
      return nums;

    int[][] ans = new int[r][c];
    int k = 0;

    for (int[] row : nums)
      for (final int num : row) {
        ans[k / c][k % c] = num;
        ++k;
      }

    return ans;
  }
}
