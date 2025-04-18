class Solution {
 public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    const int N = days.size();
    const int K = days[0].size();
    // dp[i][k] := the number of vacations that can be taken from the i-th city
    // and the k-th week
    vector<vector<int>> dp(N, vector<int>(K + 1));

    for (int k = K - 1; k >= 0; --k)
      for (int i = 0; i < N; ++i) {
        dp[i][k] = days[i][k] + dp[i][k + 1];
        for (int j = 0; j < N; ++j)
          if (flights[i][j] == 1)
            dp[i][k] = max(dp[i][k], days[j][k] + dp[j][k + 1]);
      }

    return dp[0][0];
  }
};
