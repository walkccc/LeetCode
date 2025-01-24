class Solution {
  public long maxNumber(long n) {
    // assume n = 0b00...11???
    //        x = 0b00...01111
    //  since y = 0b00...10000 is in [x, n]
    //    and x & y = 0
    final int i = 63 - Long.numberOfLeadingZeros(n);
    return (1L << i) - 1;
  }
}
