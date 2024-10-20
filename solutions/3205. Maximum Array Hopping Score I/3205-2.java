class Solution {
  public int maxScore(int[] nums) {
    // The optimal jump is the maximum number in the remaining suffix.
    int ans = 0;
    int mx = 0;

    for (int i = nums.length - 1; i > 0; --i) {
      mx = Math.max(mx, nums[i]);
      ans += mx;
    }

    return ans;
  }
}
