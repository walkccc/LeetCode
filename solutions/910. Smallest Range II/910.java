class Solution {
  public int smallestRangeII(int[] nums, int k) {
    Arrays.sort(nums);

    int ans = nums[nums.length - 1] - nums[0];
    final int left = nums[0] + k;
    final int right = nums[nums.length - 1] - k;

    for (int i = 0; i + 1 < nums.length; ++i) {
      final int mn = Math.min(left, nums[i + 1] - k);
      final int mx = Math.max(right, nums[i] + k);
      ans = Math.min(ans, mx - mn);
    }

    return ans;
  }
}
