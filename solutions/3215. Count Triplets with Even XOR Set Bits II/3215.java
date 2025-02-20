class Solution {
  // Same as 3199. Count Triplets with Even XOR Set Bits I
  public long tripletCount(int[] a, int[] b, int[] c) {
    final int[] evenOddA = getEvenOddBitCount(a);
    final int[] evenOddB = getEvenOddBitCount(b);
    final int[] evenOddC = getEvenOddBitCount(c);
    final int evenA = evenOddA[0];
    final int evenB = evenOddB[0];
    final int evenC = evenOddC[0];
    final int oddA = evenOddA[1];
    final int oddB = evenOddB[1];
    final int oddC = evenOddC[1];
    return (long) evenA * oddB * oddC + (long) oddA * evenB * oddC + (long) oddA * oddB * evenC +
        (long) evenA * evenB * evenC;
  }

  // Returns the count of numbers in the `nums` arrays that have even number of
  // ones and odd number of ones in their binary representation.
  private int[] getEvenOddBitCount(int[] nums) {
    int even = 0;
    int odd = 0;
    for (final int num : nums)
      if (Integer.bitCount(num) % 2 == 0)
        ++even;
      else
        ++odd;
    return new int[] {even, odd};
  }
}
