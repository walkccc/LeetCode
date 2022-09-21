class Solution {
  public int numPermsDISequence(String s) {
    final int kMod = 1_000_000_007;
    final int n = s.length();
    int[] dp = new int[n + 1];

    // when there's only one digit, the # of perms is 1
    for (int j = 0; j <= n; ++j)
      dp[j] = 1;

    for (int i = 1; i <= n; ++i) {
      int[] newDp = new int[n + 1];
      if (s.charAt(i - 1) == 'I') { // s[i - 1] == 'I'
        // calculate postfix sum to prevent duplicate calculation
        int postfixsum = 0;
        for (int j = n - i; j >= 0; --j) {
          postfixsum = (postfixsum + dp[j + 1]) % kMod;
          newDp[j] = postfixsum;
        }
      } else { // s[i - 1] == 'D'
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
