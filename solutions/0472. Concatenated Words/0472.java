class Solution {
  public List<String> findAllConcatenatedWordsInADict(String[] words) {
    List<String> ans = new ArrayList<>();
    Set<String> wordSet = new HashSet<>();

    for (final String word : words)
      wordSet.add(word);

    for (final String word : words)
      if (wordBreak(word, wordSet))
        ans.add(word);

    return ans;
  }

  private Map<String, Boolean> memo = new HashMap<>();

  private boolean wordBreak(final String word, Set<String> wordSet) {
    if (memo.containsKey(word))
      return memo.get(word);

    for (int i = 1; i < word.length(); ++i) {
      String prefix = word.substring(0, i);
      String suffix = word.substring(i);
      if (wordSet.contains(prefix) && (wordSet.contains(suffix) || wordBreak(suffix, wordSet))) {
        memo.put(word, true);
        return true;
      }
    }

    memo.put(word, false);
    return false;
  }
}