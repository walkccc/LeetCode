class Solution {
  public int alternatingSubarray(int[] nums) {
    int ans = 1;
    int dp = 1;

    for (int i = 1; i < nums.length; ++i) {
      final int targetDiff = dp % 2 == 0 ? -1 : 1;
      // Append nums[i] to the current alternating subarray.
      if (nums[i] - nums[i - 1] == targetDiff)
        ++dp;
      // Reset the alternating subarray to nums[i - 1..i].
      else if (nums[i] - nums[i - 1] == 1)
        dp = 2;
      // Reset the alternating subarray to nums[i].
      else
        dp = 1;
      ans = Math.max(ans, dp);
    }

    return ans == 1 ? -1 : ans;
  }
}
