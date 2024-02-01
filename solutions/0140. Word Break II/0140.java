class Solution {
  public List<String> wordBreak(String s, List<String> wordDict) {
    Set<String> wordSet = new HashSet<>(wordDict);
    Map<String, List<String>> memo = new HashMap<>();
    return wordBreak(s, wordSet, memo);
  }

  private List<String> wordBreak(final String s, Set<String> wordSet,
                                 Map<String, List<String>> memo) {
    if (memo.containsKey(s))
      return memo.get(s);

    List<String> ans = new ArrayList<>();

    // 1 <= prefix.length() < s.length()
    for (int i = 1; i < s.length(); ++i) {
      final String prefix = s.substring(0, i);
      final String suffix = s.substring(i);
      if (wordSet.contains(prefix))
        for (final String word : wordBreak(suffix, wordSet, memo))
          ans.add(prefix + " " + word);
    }

    // `wordSet` contains the whole string s, so don't add any space.
    if (wordSet.contains(s))
      ans.add(s);

    memo.put(s, ans);
    return ans;
  }
}
