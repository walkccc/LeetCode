class Solution {
  // Similar to 139. Word Break
  public int minExtraChar(String s, String[] dictionary) {
    final int n = s.length();
    Set<String> dictionarySet = new HashSet<>(Arrays.asList(dictionary));
    // dp[i] := the minimum extra letters if breaking up s[0..i) optimally
    int[] dp = new int[n + 1];
    Arrays.fill(dp, n);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
      for (int j = 0; j < i; j++)
        // s[j..i) is in the `dictionarySet`.
        if (dictionarySet.contains(s.substring(j, i)))
          dp[i] = Math.min(dp[i], dp[j]);
        // s[j..i) are extra letters.
        else
          dp[i] = Math.min(dp[i], dp[j] + i - j);

    return dp[n];
  }
}
