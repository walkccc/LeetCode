class Solution {
  public int minOperations(List<Integer> nums, int target) {
    final int NO_MISSING_BIT = 31;
    final int maxBit = 31;
    int ans = 0;
    int minMissingBit = NO_MISSING_BIT;
    // count[i] := the number of occurrences of 2^i
    int[] count = new int[maxBit + 1];

    for (final int num : nums)
      ++count[(int) (Math.log(num) / Math.log(2))];

    for (int bit = 0; bit < maxBit; ++bit) {
      // Check if `bit` is in the target.
      if ((target >> bit & 1) == 1) {
        // If there are available bits, use one bit.
        if (count[bit] > 0)
          --count[bit];
        else
          minMissingBit = Math.min(minMissingBit, bit);
      }
      // If we previously missed a bit and there are available bits.
      if (minMissingBit != NO_MISSING_BIT && count[bit] > 0) {
        --count[bit];
        // Count the operations to break `bit` into `minMissingBit`.
        ans += bit - minMissingBit;
        minMissingBit = NO_MISSING_BIT; // Set it to an the invalid value.
      }
      // Combining smaller numbers costs nothing.
      count[bit + 1] += count[bit] / 2;
    }

    // Check if all target bits have been covered, otherwise return -1.
    return minMissingBit == NO_MISSING_BIT ? ans : -1;
  }
}
