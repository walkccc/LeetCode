class Solution {
  public long maxAlternatingSum(int[] nums) {
    long even = 0; // max alternating sum ending with a even index
    long odd = 0;  // max alternating sum ending with a odd index

    for (final int num : nums) {
      even = Math.max(even, odd + num);
      odd = even - num;
    }

    return even;
  }
}
