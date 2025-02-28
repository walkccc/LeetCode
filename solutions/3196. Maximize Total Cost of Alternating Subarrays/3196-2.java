class Solution {
  public long maximumTotalCost(int[] nums) {
    // A small trick so that we don't need to handle the edge case and can use
    // ranged-based for loop.
    long keep = Long.MIN_VALUE / 2; // the maximum cost if the last number is kept
    long flip = 0;                  // the maximum cost if the last number is flipped

    for (final int num : nums) {
      final long keepCurr = Math.max(keep, flip) + num;
      final long flipCurr = keep - num;
      keep = keepCurr;
      flip = flipCurr;
    }

    return Math.max(keep, flip);
  }
}
