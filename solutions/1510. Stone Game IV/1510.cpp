class Solution {
 public:
  bool winnerSquareGame(int n) {
    // dp[i] := the winning result for n = i
    vector<bool> dp(n + 1);

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j * j <= i; ++j)
        if (!dp[i - j * j]) {  // Removing j^2 stones make the opponent lose.
          dp[i] = true;        // So, we win.
          break;
        }

    return dp[n];
  }
};
