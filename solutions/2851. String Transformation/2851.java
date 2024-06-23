class Solution {
  // This dynamic programming table dp[k][i] represents the number of ways to
  // rearrange the String s after k steps such that it starts with s[i].
  // A String can be rotated from 1 to n - 1 times. The transition rule is
  // dp[k][i] = sum(dp[k - 1][j]) for all j != i. For example, when n = 4 and
  // k = 3, the table looks like this:
  //
  // -----------------------------------------------------------
  // |       | i = 0 | i = 1 | i = 2 | i = 3 | sum = (n - 1)^k |
  // -----------------------------------------------------------
  // | k = 0 |   1   |   0   |   0   |   0   |        1        |
  // | k = 1 |   0   |   1   |   1   |   1   |        3        |
  // | k = 2 |   3   |   2   |   2   |   2   |        9        |
  // | k = 3 |   6   |   7   |   7   |   7   |       27        |
  // -----------------------------------------------------------
  //
  // By observation, we have
  //   * dp[k][!0] = ((n - 1)^k - (-1)^k) / n
  //   * dp[k][0] = dp[k][!0] + (-1)^k
  public int numberOfWays(String s, String t, long k) {
    final int n = s.length();
    final int negOnePowK = (k % 2 == 0 ? 1 : -1); // (-1)^k
    final int[] z = zFunction(s + t + t);
    final List<Integer> indices = getIndices(z, n);
    int[] dp = new int[2]; // dp[0] := dp[k][0]; dp[1] := dp[k][!0]
    dp[1] = (int) ((modPow(n - 1, k) - negOnePowK + kMod) % kMod * modPow(n, kMod - 2) % kMod);
    dp[0] = (int) ((dp[1] + negOnePowK + kMod) % kMod);
    int ans = 0;
    for (final int index : getIndices(z, n)) {
      ans += dp[index == 0 ? 0 : 1];
      ans %= kMod;
    }
    return ans;
  }

  private static final int kMod = 1_000_000_007;

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x % kMod, n / 2);
  }

  // Returns the z array, where z[i] is the length of the longest prefix of
  // s[i..n) which is also a prefix of s.
  //
  // https://cp-algorithms.com/string/z-function.html#implementation
  private int[] zFunction(final String s) {
    final int n = s.length();
    int[] z = new int[n];
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
      if (i < r)
        z[i] = Math.min(r - i, z[i - l]);
      while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i]))
        ++z[i];
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }
    return z;
  }

  // Returns the indices in `s` s.t. for each `i` in the returned indices,
  // `s[i..n) + s[0..i) = t`.
  private List<Integer> getIndices(int[] z, int n) {
    List<Integer> indices = new ArrayList<>();
    for (int i = n; i < n + n; ++i)
      if (z[i] >= n)
        indices.add(i - n);
    return indices;
  }
}
