class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    // dp[i] := the farthest position we can reach with i refuels
    vector<long> dp(stations.size() + 1);
    dp[0] = startFuel;

    for (int i = 0; i < stations.size(); ++i)
      for (int j = i + 1; j > 0; --j)
        if (dp[j - 1] >= stations[i][0])
          dp[j] = max(dp[j], dp[j - 1] + stations[i][1]);

    for (int i = 0; i < dp.size(); ++i)
      if (dp[i] >= target)
        return i;

    return -1;
  }
};
