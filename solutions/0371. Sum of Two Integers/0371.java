class Solution {
  public int getSum(int a, int b) {
    while (b != 0) {           // still have carry bits
      final int carry = a & b; // record carry bits
      a ^= b;                  // ^ works like + w/o handling carry bits
      b = carry << 1;
    }
    return a;
  }
}
