class Solution {
  public int numberOfWays(int startPos, int endPos, int k) {
    // leftStep + rightStep = k
    // rightStep - leftStep = endPos - startPos
    //        2 * rightStep = k + endPos - startPos
    //            rightStep = (k + endPos - startPos) / 2
    final int val = k + endPos - startPos;
    if (val < 0 || val % 2 == 1)
      return 0;
    final int rightStep = val / 2;
    final int leftStep = k - rightStep;
    if (leftStep < 0)
      return 0;
    return nCk(leftStep + rightStep, Math.min(leftStep, rightStep));
  }

  // C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
  private int nCk(int n, int k) {
    final int kMod = 1_000_000_007;
    // dp[i] := C(n so far, i)
    int[] dp = new int[k + 1];
    dp[0] = 1;

    while (n-- > 0) // Calculate n times.
      for (int j = k; j > 0; --j) {
        dp[j] += dp[j - 1];
        dp[j] %= kMod;
      }

    return dp[k];
  }
}
