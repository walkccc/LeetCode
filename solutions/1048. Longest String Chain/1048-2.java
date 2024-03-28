class Solution {
  public int longestStrChain(String[] words) {
    int ans = 0;
    Map<String, Integer> dp = new HashMap<>();

    Arrays.sort(words, (a, b) -> a.length() - b.length());

    for (final String word : words) {
      int bestLength = 0;
      for (int i = 0; i < word.length(); ++i) {
        final String pred = word.substring(0, i) + word.substring(i + 1);
        bestLength = Math.max(bestLength, dp.getOrDefault(pred, 0) + 1);
      }
      dp.put(word, bestLength);
      ans = Math.max(ans, bestLength);
    }

    return ans;
  }
}
