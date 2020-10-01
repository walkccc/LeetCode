class Solution {
  public List<String> wordBreak(String s, List<String> wordDict) {
    Set<String> wordSet = new HashSet<>(wordDict);
    return wordBreak(s, wordSet);
  }

  private Map<String, List<String>> memo = new HashMap<>();

  private List<String> wordBreak(final String s, Set<String> wordSet) {
    if (memo.containsKey(s))
      return memo.get(s);

    List<String> ans = new ArrayList<>();

    if (wordSet.contains(s))
      ans.add(s);

    for (int i = 1; i < s.length(); ++i) {
      final String suffix = s.substring(i);
      if (wordSet.contains(suffix))
        for (final String word : wordBreak(s.substring(0, i), wordSet))
          ans.add(word + " " + suffix);
    }

    memo.put(s, ans);
    return ans;
  }
}