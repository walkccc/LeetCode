class Solution {
  public long minimumTime(int[] power) {
    final int n = power.length;
    final int maxMask = 1 << n;
    // dp[i] := min # of days needed to defeat monsters,
    // where i is the bit representation of monsters
    long[] dp = new long[maxMask];
    Arrays.fill(dp, Long.MAX_VALUE);
    dp[0] = 0;

    for (int mask = 1; mask < maxMask; ++mask) {
      final int currentGain = Integer.bitCount(mask);
      for (int i = 0; i < n; ++i)
        if ((mask >> i & 1) == 1)
          dp[mask] = Math.min(dp[mask], dp[mask & ~(1 << i)] +
                                            (int) (Math.ceil(power[i] * 1.0 / currentGain)));
    }

    return dp[maxMask - 1];
  }
}
