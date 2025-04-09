class Solution {
  public int[] gcdValues(int[] nums, long[] queries) {
    int maxNum = Arrays.stream(nums).max().getAsInt();
    int[] ans = new int[queries.length];
    // countDivisor[d] := the number of `nums` having `num % d == 0`
    int[] countDivisor = new int[maxNum + 1];
    // countGcdPair[g] := the number of pairs having gcd == g
    long[] countGcdPair = new long[maxNum + 1];
    // prefixCountGcdPair[g] := the number of pairs having gcd <= g
    long[] prefixCountGcdPair = new long[maxNum + 1];

    for (final int num : nums)
      for (int i = 1; i * i <= num; ++i)
        if (num % i == 0) {
          ++countDivisor[i];
          if (i != num / i)
            ++countDivisor[num / i];
        }

    for (int gcd = maxNum; gcd >= 1; --gcd) {
      // There are C(countDivisor[gcd], 2) pairs that have a common divisor
      // that's a multiple of `gcd` (including the one that equals to `gcd`).
      // So, substract the multiples of `gcd` to have the number of pairs with a
      // gcd that's exactly `gcd`.
      countGcdPair[gcd] = (long) countDivisor[gcd] * (countDivisor[gcd] - 1) / 2;
      for (int largerGcd = 2 * gcd; largerGcd <= maxNum; largerGcd += gcd)
        countGcdPair[gcd] -= countGcdPair[largerGcd];
    }

    for (int gcd = 1; gcd <= maxNum; ++gcd)
      prefixCountGcdPair[gcd] = prefixCountGcdPair[gcd - 1] + countGcdPair[gcd];

    for (int i = 0; i < queries.length; ++i)
      ans[i] = getNthGcdPair(queries[i], prefixCountGcdPair);

    return ans;
  }

  // Returns the `query`-th gcd pair.
  private int getNthGcdPair(long query, long[] prefixCountGcdPair) {
    int l = 1;
    int r = prefixCountGcdPair.length - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (prefixCountGcdPair[m] < query + 1)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
}
