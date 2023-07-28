class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    return wordBreak(s, new HashSet<>(wordDict), new HashMap<>());
  }

  private boolean wordBreak(final String s, Set<String> wordSet, Map<String, Boolean> memo) {
    if (memo.containsKey(s))
      return memo.get(s);
    if (wordSet.contains(s)) {
      memo.put(s, true);
      return true;
    }

    // 1 <= prefix.length() < s.length()
    for (int i = 1; i < s.length(); ++i) {
      final String prefix = s.substring(0, i);
      final String suffix = s.substring(i);
      if (wordSet.contains(prefix) && wordBreak(suffix, wordSet, memo)) {
        memo.put(s, true);
        return true;
      }
    }

    memo.put(s, false);
    return false;
  }
}
