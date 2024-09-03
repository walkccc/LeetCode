class Solution {
  // Same as 3205. Maximum Array Hopping Score I
  public long maxScore(int[] nums) {
    // The optimal next step is the highest number in the remaining suffix.
    long ans = 0;
    int suffixMax = 0;

    for (int i = nums.length - 1; i > 0; --i) {
      suffixMax = Math.max(suffixMax, nums[i]);
      ans += suffixMax;
    }

    return ans;
  }
}
