class Solution {
  public int numWays(String[] words, String target) {
    final int MOD = 1_000_000_007;
    final int wordLength = words[0].length();
    // dp[i][j] := the number of ways to form the first i characters of the
    // `target` using the j first characters in each word
    int[][] dp = new int[target.length() + 1][wordLength + 1];
    // counts[j] := the count map of words[i][j], where 0 <= i < |words|
    int[][] counts = new int[wordLength][26];

    for (int i = 0; i < wordLength; ++i)
      for (final String word : words)
        ++counts[i][word.charAt(i) - 'a'];

    dp[0][0] = 1;

    for (int i = 0; i <= target.length(); ++i)
      for (int j = 0; j < wordLength; ++j) {
        if (i < target.length())
          // Pick the character target[i] from word[j].
          dp[i + 1][j + 1] = (int) ((long) dp[i][j] * counts[j][target.charAt(i) - 'a'] % MOD);
        // Skip the word[j].
        dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
      }

    return dp[target.length()][wordLength];
  }
}
