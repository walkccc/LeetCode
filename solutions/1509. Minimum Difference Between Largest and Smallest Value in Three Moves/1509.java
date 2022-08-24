class Solution {
  public int minDifference(int[] nums) {
    final int n = nums.length;
    if (n < 5)
      return 0;

    int ans = Integer.MAX_VALUE;

    Arrays.sort(nums);

    // change nums[0..i) to nums[i] and
    // change nums[n - 3 + i..n) to nums[n - 4 + i]
    for (int i = 0; i <= 3; ++i)
      ans = Math.min(ans, nums[n - 4 + i] - nums[i]);

    return ans;
  }
}
