class Solution {
  public int countVowelStrings(int n) {
    // dp[0] := # of lexicographically sorted strings ends with 'a'
    // dp[1] := # of lexicographically sorted strings ends with 'e'
    // dp[2] := # of lexicographically sorted strings ends with 'i'
    // dp[3] := # of lexicographically sorted strings ends with 'o'
    // dp[4] := # of lexicographically sorted strings ends with 'u'
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
