class Solution {
  public List<String> findAllConcatenatedWordsInADict(String[] words) {
    List<String> ans = new ArrayList<>();
    Set<String> wordSet = new HashSet<>(Arrays.asList(words));
    Map<String, Boolean> memo = new HashMap<>();

    for (final String word : words)
      if (wordBreak(word, wordSet, memo))
        ans.add(word);

    return ans;
  }

  private boolean wordBreak(final String word, Set<String> wordSet, Map<String, Boolean> memo) {
    if (memo.containsKey(word))
      return memo.get(word);

    for (int i = 1; i < word.length(); ++i) {
      final String prefix = word.substring(0, i);
      final String suffix = word.substring(i);
      if (wordSet.contains(prefix) &&
          (wordSet.contains(suffix) || wordBreak(suffix, wordSet, memo))) {
        memo.put(word, true);
        return true;
      }
    }

    memo.put(word, false);
    return false;
  }
}
