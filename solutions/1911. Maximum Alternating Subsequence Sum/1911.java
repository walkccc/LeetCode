class Solution {
  public long maxAlternatingSum(int[] nums) {
    long even = 0; // the maximum alternating sum ending in an even index
    long odd = 0;  // the maximum alternating sum ending in an odd index

    for (final int num : nums) {
      even = Math.max(even, odd + num);
      odd = even - num;
    }

    return even;
  }
}
