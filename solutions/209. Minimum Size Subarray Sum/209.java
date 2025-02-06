class Solution {
  public int minSubArrayLen(int target, int[] nums) {
    int ans = Integer.MAX_VALUE;
    int sum = 0;

    for (int l = 0, r = 0; r < nums.length; ++r) {
      sum += nums[r];
      while (sum >= target) {
        ans = Math.min(ans, r - l + 1);
        sum -= nums[l++];
      }
    }

    return ans == Integer.MAX_VALUE ? 0 : ans;
  }
}
