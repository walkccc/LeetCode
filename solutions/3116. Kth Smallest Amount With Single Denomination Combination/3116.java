class Solution {
  public long findKthSmallest(int[] coins, int k) {
    List<Long>[] sizeToLcms = getSizeToLcms(coins);
    long l = 0;
    long r = (long) k * Arrays.stream(coins).min().getAsInt();

    while (l < r) {
      final long m = (l + r) / 2;
      if (numDenominationsNoGreaterThan(sizeToLcms, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  // Returns the number of denominations <= m.
  private long numDenominationsNoGreaterThan(List<Long>[] sizeToLcms, long m) {
    long res = 0;
    for (int sz = 1; sz < sizeToLcms.length; ++sz)
      for (long lcm : sizeToLcms[sz])
        res += m / lcm * Math.pow(-1, sz + 1);
    return res;
  }

  // Returns the LCMs for each number of combination of coins.
  private List<Long>[] getSizeToLcms(int[] coins) {
    final int n = coins.length;
    final int maxMask = 1 << n;
    List<Long>[] sizeToLcms = new List[n + 1];

    for (int i = 1; i <= n; ++i)
      sizeToLcms[i] = new ArrayList<>();

    for (int mask = 1; mask < maxMask; ++mask) {
      long lcmOfSelectedCoins = 1;
      for (int i = 0; i < n; ++i)
        if ((mask >> i & 1) == 1)
          lcmOfSelectedCoins = lcm(lcmOfSelectedCoins, coins[i]);
      sizeToLcms[Integer.bitCount(mask)].add(lcmOfSelectedCoins);
    }

    return sizeToLcms;
  }

  private long lcm(long a, long b) {
    return a * b / gcd(a, b);
  }

  private long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
