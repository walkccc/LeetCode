class Solution {
  public int minimizeSum(int[] nums) {
    Arrays.sort(nums);
    // Can always change the number to any other number in `nums`, so `low` becomes 0.
    // Thus, rephrase the problem as finding the minimum `high`.
    final int n = nums.length;
    final int highOfChangingTwoMins = nums[n - 1] - nums[2];
    final int highOfChangingTwoMaxs = nums[n - 3] - nums[0];
    final int highOfChangingMinAndMax = nums[n - 2] - nums[1];
    return Math.min(Math.min(highOfChangingTwoMins, highOfChangingTwoMaxs),
                    highOfChangingMinAndMax);
  }
}
