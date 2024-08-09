class Solution {
  public int[] findProductsOfElements(long[][] queries) {
    int[] ans = new int[queries.length];

    for (int i = 0; i < queries.length; ++i) {
      final long a = queries[i][0];
      final long b = queries[i][1];
      final int mod = (int) queries[i][2];
      ans[i] = (int) modPow(2,
                            sumPowersFirstKBigNums(b + 1) - //
                                sumPowersFirstKBigNums(a),
                            mod);
    }

    return ans;
  }

  // Returns the sum of powers of the first k numbers in `big_nums`.
  private long sumPowersFirstKBigNums(long k) {
    final long num = firstNumberHavingSumBitsTillGreaterThan(k);
    long sumPowers = sumPowersTill(num - 1);
    long remainingCount = k - sumBitsTill(num - 1);
    for (int power = 0; power < bitLength(num); ++power) {
      if ((num >> power & 1) == 1) {
        sumPowers += power;
        --remainingCount;
        if (remainingCount == 0)
          break;
      }
    }
    return sumPowers;
  }

  // Returns the first number in [1, k] that has sumBitsTill(num) >= k.
  private long firstNumberHavingSumBitsTillGreaterThan(long k) {
    long l = 1;
    long r = k;
    while (l < r) {
      final long m = (l + r) / 2;
      if (sumBitsTill(m) < k)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }

  // Returns sum(i.bit_count()), where 1 <= i <= x.
  private long sumBitsTill(long x) {
    long sumBits = 0;
    for (long powerOfTwo = 1; powerOfTwo <= x; powerOfTwo *= 2) {
      sumBits += (x / (2 * powerOfTwo)) * powerOfTwo;
      sumBits += Math.max(0, x % (2 * powerOfTwo) + 1 - powerOfTwo);
    }
    return sumBits;
  }

  // Returns sum(all powers of i), where 1 <= i <= x.
  private long sumPowersTill(long x) {
    long sumPowers = 0;
    long powerOfTwo = 1;
    for (int power = 0; power < bitLength(x); ++power) {
      sumPowers += (x / (2 * powerOfTwo)) * powerOfTwo * power;
      sumPowers += Math.max(0, x % (2 * powerOfTwo) + 1 - powerOfTwo) * power;
      powerOfTwo *= 2;
    }
    return sumPowers;
  }

  private long modPow(long x, long n, int mod) {
    if (n == 0)
      return 1 % mod;
    if (n % 2 == 1)
      return x * modPow(x % mod, (n - 1), mod) % mod;
    return modPow(x * x % mod, (n / 2), mod) % mod;
  }

  private int bitLength(long x) {
    return x == 0 ? 0 : 64 - Long.numberOfLeadingZeros(x);
  }
}
