class Solution {
  public int minimumSubstringsInPartition(String s) {
    final int n = s.length();
    // dp[i] := the minimum number of substrings in s[0..i]
    int[] dp = new int[n];
    Arrays.fill(dp, n);

    for (int i = 0; i < n; ++i) {
      int[] count = new int[26];
      for (int j = i; j >= 0; --j) {
        ++count[s.charAt(j) - 'a'];
        if (isBalanced(count)) // word[j..i] is balanced.
          dp[i] = j > 0 ? Math.min(dp[i], 1 + dp[j - 1]) : 1;
      }
    }

    return dp[n - 1];
  }

  private static final int kMax = 1001;

  // Returns true if all non-zero frequencies are the same.
  private boolean isBalanced(int[] count) {
    int minfreq = kMax;
    int maxfreq = 0;
    for (final int freq : count)
      if (freq > 0) {
        minfreq = Math.min(minfreq, freq);
        maxfreq = Math.max(maxfreq, freq);
      }
    return minfreq == maxfreq;
  }
}
