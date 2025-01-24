class Solution {
  public int minimumDifference(int[] nums, int k) {
    Arrays.sort(nums);

    int ans = nums[k - 1] - nums[0];

    for (int i = k; i < nums.length; ++i)
      ans = Math.min(ans, nums[i] - nums[i - k + 1]);

    return ans;
  }
}
