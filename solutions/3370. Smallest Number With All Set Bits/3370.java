class Solution {
  public int smallestNumber(int n) {
    return (1 << bitLength(n)) - 1;
  }

  private int bitLength(int n) {
    return Integer.SIZE - Integer.numberOfLeadingZeros(n);
  }
}
