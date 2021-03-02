class Solution {
  public int findKthNumber(int n, int k) {
    long currNum = 1;

    for (int i = 1; i < k;) {
      long gap = getGap(currNum, currNum + 1, n);
      if (i + gap <= k) {
        i += gap;
        ++currNum;
      } else {
        ++i;
        currNum *= 10;
      }
    }

    return (int) currNum;
  }

  private long getGap(long a, long b, long n) {
    long gap = 0;
    while (a <= n) {
      gap += Math.min(n + 1, b) - a;
      a *= 10;
      b *= 10;
    }
    return gap;
  }
}
