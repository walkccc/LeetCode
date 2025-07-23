class Solution {
  public int minimumCost(String target, String[] words, int[] costs) {
    final int kMax = 1_000_000_000;
    final int n = target.length();
    // dp[i] := the minimum cost to construct target[0..i)
    int[] dp = new int[n + 1];
    Arrays.fill(dp, kMax);
    dp[0] = 0;
    // minCost[c][word] := the minimum cost to construct word starting with `c`
    Map<String, Integer>[] minCost = new HashMap[26];

    for (int i = 0; i < 26; ++i)
      minCost[i] = new HashMap<>();

    for (int i = 0; i < words.length; ++i) {
      final int index = words[i].charAt(0) - 'a';
      final String word = words[i];
      minCost[index].put(word, Math.min(minCost[index].getOrDefault(word, kMax), costs[i]));
    }

    for (int i = 0; i < n; ++i)
      for (Map.Entry<String, Integer> entry : minCost[target.charAt(i) - 'a'].entrySet()) {
        final String word = entry.getKey();
        final int cost = entry.getValue();
        final int j = i + word.length();
        if (j <= n && cost + dp[i] < dp[j] && isMatch(target, i, word))
          dp[j] = cost + dp[i];
      }

    return dp[n] == kMax ? -1 : dp[n];
  }

  private boolean isMatch(final String target, int start, final String word) {
    for (int i = 0; i < word.length(); ++i)
      if (target.charAt(start + i) != word.charAt(i))
        return false;
    return true;
  }
}
