class Solution {
 public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    const int N = days.size();
    const int K = days[0].size();
    // dp[i] := the number of vacations that can be taken from the i-th city
    vector<int> dp(N);

    for (int k = K - 1; k >= 0; --k) {
      vector<int> newDp(N);
      for (int i = 0; i < N; ++i) {
        newDp[i] = days[i][k] + dp[i];
        for (int j = 0; j < N; ++j)
          if (flights[i][j] == 1)
            newDp[i] = max(newDp[i], days[j][k] + dp[j]);
      }
      dp = move(newDp);
    }

    return dp[0];
  }
};
