class Solution {
  public int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    final long divisorLcm = lcm(divisor1, divisor2);
    long l = 0;
    long r = Integer.MAX_VALUE;

    while (l < r) {
      final long m = (l + r) / 2;
      if (isPossible(m, divisorLcm, divisor1, divisor2, uniqueCnt1, uniqueCnt2))
        r = m;
      else
        l = m + 1;
    }

    return (int) l;
  }

  // Returns true if we can take uniqueCnt1 integers from [1..m] to arr1 and
  // take uniqueCnt2 integers from [1..m] to arr2.
  private boolean isPossible(long m, long divisorLcm, int divisor1, int divisor2, int uniqueCnt1,
                             int uniqueCnt2) {
    final long cnt1 = m - m / divisor1;
    final long cnt2 = m - m / divisor2;
    final long totalCnt = m - m / divisorLcm;
    return cnt1 >= uniqueCnt1 && cnt2 >= uniqueCnt2 && totalCnt >= uniqueCnt1 + uniqueCnt2;
  }

  private long gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  private long lcm(int a, int b) {
    return a * (b / gcd(a, b));
  }
}
