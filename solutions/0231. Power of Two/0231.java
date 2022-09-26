class Solution {
  public boolean isPowerOfTwo(int n) {
    return n < 0 ? false : Integer.bitCount(n) == 1;
  }
}
