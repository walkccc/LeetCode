class Solution {
  public int rangeBitwiseAnd(int m, int n) {
    int shiftBits = 0;

    while (m != n) {
      m >>= 1;
      n >>= 1;
      ++shiftBits;
    }

    return m << shiftBits;
  }
}