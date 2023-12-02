class Solution {
 public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    // dp[i][j] := the number of vacations that can be taken from the i-th city
    // and the k-th week
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

    // Stay at the j-th city or fly from the i-th city to the j-th city.
    for (int j = 0; j < flights.size(); ++j)
      if (j == i || flights[i][j] == 1)
        ans = max(ans, days[j][k] + maxVacationDays(flights, days, j, k + 1));

    return dp[i][k] = ans;
  }
};
