class Solution {
  public int numberOfWays(int numPeople) {
    final long kMod = 1_000_000_007;
    // dp[i] := # of ways i handshakes pair w/o crossing
    long[] dp = new long[numPeople / 2 + 1];
    dp[0] = 1;

    for (int i = 1; i <= numPeople / 2; ++i)
      for (int j = 0; j < i; ++j) {
        dp[i] += dp[j] * dp[i - 1 - j];
        dp[i] %= kMod;
      }

    return (int) dp[numPeople / 2];
  }
}
