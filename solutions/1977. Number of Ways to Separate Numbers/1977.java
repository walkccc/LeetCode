class Solution {
  public int numberOfCombinations(String num) {
    if (num.charAt(0) == '0')
      return 0;

    final int kMod = 1_000_000_007;
    final int n = num.length();
    // dp[i][k] := the number of possible lists of integers ending in num[i] with
    // the length of the last number being 1..k
    long[][] dp = new long[n][n + 1];
    // lcs[i][j] := the number of the same digits in num[i..n) and num[j..n)
    int[][] lcs = new int[n + 1][n + 1];

    for (int i = n - 1; i >= 0; --i)
      for (int j = i + 1; j < n; ++j)
        if (num.charAt(i) == num.charAt(j))
          lcs[i][j] = lcs[i + 1][j + 1] + 1;

    for (int i = 0; i < n; ++i)
      for (int k = 1; k <= i + 1; ++k) {
        dp[i][k] += dp[i][k - 1];
        dp[i][k] %= kMod;
        // The last number is num[s..i].
        final int s = i - k + 1;
        if (num.charAt(s) == '0')
          // the number of possible lists of integers ending in num[i] with the
          // length of the last number being k
          continue;
        if (s == 0) {
          // the whole string
          dp[i][k] += 1;
          continue;
        }
        if (s < k) {
          // The length k is not enough, so add the number of possible lists of
          // integers in num[0..s - 1].
          dp[i][k] += dp[s - 1][s];
          continue;
        }
        final int l = lcs[s - k][s];
        if (l >= k || num.charAt(s - k + l) <= num.charAt(s + l))
          // Have enough length k and num[s - k..s - 1] <= num[j..i].
          dp[i][k] += dp[s - 1][k];
        else
          // Have enough length k but num[s - k..s - 1] > num[j..i].
          dp[i][k] += dp[s - 1][k - 1];
      }

    return (int) dp[n - 1][n] % kMod;
  }
}
