class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    return wordBreak(s, 0, new HashSet<>(wordDict), new Boolean[s.length()]);
  }

  // Returns true if s[i..n) can be segmented.
  private boolean wordBreak(final String s, int i, Set<String> wordSet, Boolean[] memo) {
    if (i == s.length())
      return true;
    if (memo[i] != null)
      return memo[i];

    for (int j = i + 1; j <= s.length(); ++j)
      if (wordSet.contains(s.substring(i, j)) && wordBreak(s, j, wordSet, memo))
        return memo[i] = true;

    return memo[i] = false;
  }
}
