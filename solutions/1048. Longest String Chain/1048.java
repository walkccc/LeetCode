class Solution {
  public int longestStrChain(String[] words) {
    Set<String> wordsSet = new HashSet<>(Arrays.asList(words));
    int ans = 0;

    for (final String word : words)
      ans = Math.max(ans, longestStrChain(word, wordsSet));

    return ans;
  }
  // dp[s] := longest string chain where s is the last word
  private Map<String, Integer> dp = new HashMap<>();

  private int longestStrChain(final String s, Set<String> wordsSet) {
    if (dp.containsKey(s))
      return dp.get(s);

    int ans = 1;

    for (int i = 0; i < s.length(); ++i) {
      final String pred = s.substring(0, i) + s.substring(i + 1);
      if (wordsSet.contains(pred))
        ans = Math.max(ans, longestStrChain(pred, wordsSet) + 1);
    }

    dp.put(s, ans);
    return ans;
  }
}
