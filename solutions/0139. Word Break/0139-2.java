class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    Set<String> wordSet = new HashSet<>(wordDict);
    return wordBreak(s, wordSet);
  }

  private Map<String, Boolean> memo = new HashMap<>();

  private boolean wordBreak(final String s, Set<String> wordSet) {
    if (memo.containsKey(s))
      return memo.get(s);
    if (wordSet.contains(s)) {
      memo.put(s, true);
      return true;
    }

    for (int i = 1; i < s.length(); ++i) {
      final String prefix = s.substring(0, i);
      final String suffix = s.substring(i);
      if (wordSet.contains(prefix) && wordBreak(suffix, wordSet)) {
        memo.put(s, true);
        return true;
      }
    }

    memo.put(s, false);
    return false;
  }
}