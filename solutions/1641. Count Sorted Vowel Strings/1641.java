class Solution {
  public int countVowelStrings(int n) {
    // dp[0] := the number of lexicographically sorted string that end in 'a'
    // dp[1] := the number of lexicographically sorted string that end in 'e'
    // dp[2] := the number of lexicographically sorted string that end in 'i'
    // dp[3] := the number of lexicographically sorted string that end in 'o'
    // dp[4] := the number of lexicographically sorted string that end in 'u'
    int[] dp = new int[5];
    Arrays.fill(dp, 1);

    for (int i = 2; i <= n; ++i) {
      int[] newDp = new int[5];
      for (int j = 0; j < 5; ++j)
        for (int k = 0; k <= j; ++k)
          newDp[j] += dp[k];
      dp = newDp;
    }

    return Arrays.stream(dp).sum();
  }
}
