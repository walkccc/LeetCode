class Solution {
  public int maxScore(int[] nums) {
    // The optimal next step is the highest number in the remaining suffix.
    int ans = 0;
    int suffixMax = 0;

    for (int i = nums.length - 1; i > 0; --i) {
      suffixMax = Math.max(suffixMax, nums[i]);
      ans += suffixMax;
    }

    return ans;
  }
}
