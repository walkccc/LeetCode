class Solution {
  public boolean winnerSquareGame(int n) {
    // dp[i] := the winning result for n = i
    boolean[] dp = new boolean[n + 1];

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j * j <= i; ++j)
        if (!dp[i - j * j]) { // remove j^2 stones make the opponent lose
          dp[i] = true;       // so we win
          break;
        }

    return dp[n];
  }
}
