class Solution {
  public int maximumDifference(int[] nums) {
    int ans = -1;
    int min = nums[0];

    for (int i = 1; i < nums.length; ++i) {
      if (nums[i] > min)
        ans = Math.max(ans, nums[i] - min);
      min = Math.min(min, nums[i]);
    }

    return ans;
  }
}
