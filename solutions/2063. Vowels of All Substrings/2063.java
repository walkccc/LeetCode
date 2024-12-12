class Solution {
  public long countVowels(String word) {
    // dp[i] := the sum of the number of vowels of word[0..i), ...,
    // word[i - 1..i)
    long[] dp = new long[word.length() + 1];

    for (int i = 1; i <= word.length(); ++i) {
      dp[i] = dp[i - 1];
      if (isVowel(word.charAt(i - 1)))
        dp[i] += i;
    }

    return Arrays.stream(dp).sum();
  }

  private boolean isVowel(char c) {
    return "aeiou".indexOf(c) != -1;
  }
}
