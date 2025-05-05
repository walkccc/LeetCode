class Solution {
  public long countSubstrings(String s) {
    long ans = 0;
    // dp[num][rem] := the number of substrings so far that have a remainder of
    // `rem` when divided by `num`
    int[][] dp = new int[10][10];

    for (final char c : s.toCharArray()) {
      final int digit = c - '0';
      int[][] newDp = new int[10][10];
      for (int num = 1; num < 10; ++num) {
        for (int rem = 0; rem < num; ++rem)
          newDp[num][(rem * 10 + digit) % num] += dp[num][rem];
        ++newDp[num][digit % num];
      }
      dp = newDp;
      ans += dp[digit][0];
    }

    return ans;
  }
}
