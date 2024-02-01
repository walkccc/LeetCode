class Solution {
  public int matrixSum(int[][] nums) {
    int ans = 0;

    for (int[] row : nums)
      Arrays.sort(row);

    for (int j = 0; j < nums[0].length; ++j) {
      int maxi = 0;
      for (int i = 0; i < nums.length; ++i)
        maxi = Math.max(maxi, nums[i][j]);
      ans += maxi;
    }

    return ans;
  }
}
