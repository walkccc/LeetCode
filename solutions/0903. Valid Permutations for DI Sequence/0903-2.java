class Solution {
  public int numPermsDISequence(String S) {
    final int kMod = (int) 1e9 + 7;
    final int n = S.length();

    int[] dp = new int[n + 1];

    // when there's only one digit, the # of perms is 1
    for (int j = 0; j <= n; ++j)
      dp[j] = 1;

    for (int i = 1; i <= n; ++i) {
      int[] newDp = new int[n + 1];
      if (S.charAt(i - 1) == 'I') { // S[i - 1] == 'I'
        // calculate postfix sum to prevent duplicate calculation
        int postfixSum = 0;
        for (int j = n - i; j >= 0; --j) {
          postfixSum = (postfixSum + dp[j + 1]) % kMod;
          newDp[j] = postfixSum;
        }
      } else { // S[i - 1] == 'D'
        // calculate prefix sum to prevent duplicate calculation
        int prefix = 0;
        for (int j = 0; j <= n - i; ++j) {
          prefix = (prefix + dp[j]) % kMod;
          newDp[j] = prefix;
        }
      }
      dp = newDp;
    }

    return dp[0];
  }
}
