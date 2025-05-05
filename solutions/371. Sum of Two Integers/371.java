class Solution {
  public int getSum(int a, int b) {
    while (b != 0) {           // Still have carry bits.
      final int carry = a & b; // Record the carry bits.
      a ^= b;                  // ^ works like + without handling carry bits.
      b = carry << 1;
    }
    return a;
  }
}
