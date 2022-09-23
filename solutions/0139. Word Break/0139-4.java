class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    final int n = s.length();
    final int maxLength = getMaxLength(wordDict);
    Set<String> wordSet = new HashSet<>(wordDict);
    // dp[i] := true if s[0..i) can be segmented
    boolean[] dp = new boolean[n + 1];
    dp[0] = true;

    for (int i = 1; i <= n; ++i)
      for (int j = i - 1; j >= 0; --j) {
        if (i - j > maxLength)
          break;
        // s[0..j) can be segmented and s[j..i) in wordSet
        // so s[0..i) can be segmented
        if (dp[j] && wordSet.contains(s.substring(j, i))) {
          dp[i] = true;
          break;
        }
      }

    return dp[n];
  }

  private int getMaxLength(List<String> wordDict) {
    return wordDict.stream().mapToInt(String::length).max().getAsInt();
  }
}
