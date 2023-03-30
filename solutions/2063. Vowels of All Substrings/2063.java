class Solution {
  public long countVowels(String word) {
    // dp[i] := sum of the # of vowels of word[:i], ..., word[i - 1:i]
    long[] dp = new long[word.length() + 1];

    for (int i = 1; i <= word.length(); ++i) {
      dp[i] = dp[i - 1];
      if ("aeiou".indexOf(word.charAt(i - 1)) != -1)
        dp[i] += i;
    }

    return Arrays.stream(dp).sum();
  }
}
