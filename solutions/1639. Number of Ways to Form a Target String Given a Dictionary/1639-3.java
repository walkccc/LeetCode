class Solution {
  public int numWays(String[] words, String target) {
    final int kMod = 1_000_000_007;
    final int wordLength = words[0].length();
    // dp[i] := the number of ways to form the first i characters of `target`
    long[] dp = new long[target.length() + 1];
    dp[0] = 1;

    for (int j = 0; j < wordLength; ++j) {
      int[] count = new int[26];
      for (final String word : words)
        ++count[word.charAt(j) - 'a'];
      for (int i = target.length(); i > 0; --i) {
        dp[i] += dp[i - 1] * count[target.charAt(i - 1) - 'a'];
        dp[i] %= kMod;
      }
    }

    return (int) dp[target.length()];
  }
}
