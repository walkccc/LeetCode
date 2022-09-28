class Solution {
 public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    // dp[i][j] := # of vacations can be taken from i-th city and k-th week
    dp.resize(days.size(), vector<int>(days[0].size(), INT_MIN));
    return maxVacationDays(flights, days, 0, 0);
  }

 private:
  vector<vector<int>> dp;

  int maxVacationDays(const vector<vector<int>>& flights,
                      const vector<vector<int>>& days, int i, int k) {
    if (k == days[0].size())
      return 0;
    if (dp[i][k] != INT_MIN)
      return dp[i][k];

    int ans = 0;

    // stay at j or fly from i -> j
    for (int j = 0; j < flights.size(); ++j)
      if (j == i || flights[i][j] == 1)
        ans = max(ans, days[j][k] + maxVacationDays(flights, days, j, k + 1));

    return dp[i][k] = ans;
  }
};
