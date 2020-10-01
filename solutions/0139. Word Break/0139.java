class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    final int n = s.length();

    Set<String> wordSet = new HashSet<>(wordDict);
    boolean[] dp = new boolean[n + 1]; // dp[i] := true if s[0..i) can be segmented
    dp[0] = true;

    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < i; ++j)
        if (dp[j] && wordSet.contains(s.substring(j, i))) {
          dp[i] = true;
          break;
        }

    return dp[n];
  }
}