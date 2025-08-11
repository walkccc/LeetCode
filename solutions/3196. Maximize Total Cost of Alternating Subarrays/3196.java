class Solution {
  public long maximumTotalCost(int[] nums) {
    long keep = nums[0]; // the maximum cost if the last number is kept
    long flip = nums[0]; // the maximum cost if the last number is flipped

    for (int i = 1; i < nums.length; ++i) {
      final long keepCurr = Math.max(keep, flip) + nums[i];
      final long flipCurr = keep - nums[i];
      keep = keepCurr;
      flip = flipCurr;
    }

    return Math.max(keep, flip);
  }
}
