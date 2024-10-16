class Solution {
  public int minimumCost(String sentence, int k) {
    if (sentence.length() <= k)
      return 0;

    String[] words = sentence.split(" ");
    // dp[i] := the minimum cost of the first i words
    int[] dp = new int[words.length + 1];

    for (int i = 1; i <= words.length; ++i) {
      int n = words[i - 1].length(); // the length of the current row
      dp[i] = dp[i - 1] + (k - n) * (k - n);
      // Gradually add words[j - 1], words[j - 2], ....
      for (int j = i - 1; j > 0; --j) {
        n += words[j - 1].length() + 1;
        if (n > k)
          break;
        dp[i] = Math.min(dp[i], dp[j - 1] + (k - n) * (k - n));
      }
    }

    int lastRowLen = words[words.length - 1].length();
    int i = words.length - 2;

    while (i > 0 && lastRowLen + words[i].length() + 1 <= k)
      lastRowLen += words[i--].length();

    return Arrays.stream(dp, i + 1, words.length).min().getAsInt();
  }
}
