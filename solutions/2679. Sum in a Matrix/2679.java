class Solution {
  public int matrixSum(int[][] nums) {
    int ans = 0;

    for (int[] row : nums)
      Arrays.sort(row);

    for (int j = 0; j < nums[0].length; ++j) {
      int mx = 0;
      for (int i = 0; i < nums.length; ++i)
        mx = Math.max(mx, nums[i][j]);
      ans += mx;
    }

    return ans;
  }
}
