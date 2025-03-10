class Solution {
  public int minimumCost(String target, String[] words, int[] costs) {
    final int n = target.length();
    // dp[i] := the minimum cost to construct target[0..i)
    int[] dp = new int[n + 1];
    Arrays.fill(dp, Integer.MAX_VALUE);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < words.length; ++j)
        if (i >= words[j].length() && //
            target.substring(i - words[j].length(), i).equals(words[j]) &&
            dp[i - words[j].length()] != Integer.MAX_VALUE)
          dp[i] = Math.min(dp[i], dp[i - words[j].length()] + costs[j]);

    return dp[n] == Integer.MAX_VALUE ? -1 : dp[n];
  }
}
