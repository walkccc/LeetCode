class Solution {
  // Same as 3205. Maximum Array Hopping Score I
  public long maxScore(int[] nums) {
    // The optimal jump is the maximum number in the remaining suffix.
    long ans = 0;
    int mx = 0;

    for (int i = nums.length - 1; i > 0; --i) {
      mx = Math.max(mx, nums[i]);
      ans += mx;
    }

    return ans;
  }
}
