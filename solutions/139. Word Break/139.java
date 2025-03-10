class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    return wordBreak(s, new HashSet<>(wordDict), new HashMap<>());
  }

  private boolean wordBreak(final String s, Set<String> wordSet, Map<String, Boolean> mem) {
    if (mem.containsKey(s))
      return mem.get(s);
    if (wordSet.contains(s)) {
      mem.put(s, true);
      return true;
    }

    // 1 <= prefix.length() < s.length()
    for (int i = 1; i < s.length(); ++i) {
      final String prefix = s.substring(0, i);
      final String suffix = s.substring(i);
      if (wordSet.contains(prefix) && wordBreak(suffix, wordSet, mem)) {
        mem.put(s, true);
        return true;
      }
    }

    mem.put(s, false);
    return false;
  }
}
