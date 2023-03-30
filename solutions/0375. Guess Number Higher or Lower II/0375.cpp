class Solution {
 public:
  int getMoneyAmount(int n) {
    // dp[i][j] := min money you need to guarantee a win of picking i..j
    dp.resize(n + 1, vector<int>(n + 1, INT_MAX));
    return getMoneyAmount(1, n);
  }

 private:
  vector<vector<int>> dp;

  int getMoneyAmount(int i, int j) {
    if (i >= j)
      return 0;
    if (dp[i][j] != INT_MAX)
      return dp[i][j];

    for (int k = i; k <= j; ++k)
      dp[i][j] =
          min(dp[i][j],
              max(getMoneyAmount(i, k - 1), getMoneyAmount(k + 1, j)) + k);

    return dp[i][j];
  }
};
