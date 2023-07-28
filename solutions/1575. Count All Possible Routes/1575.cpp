class Solution {
 public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    // dp[i][j] := # of ways to reach `finish` from i-th city with j fuel
    dp.resize(locations.size(), vector<int>(fuel + 1, -1));
    vector<vector<int>> dp(locations.size(), vector<int>(fuel + 1, -1));
    return count(locations, start, finish, fuel);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<vector<int>> dp;

  int count(const vector<int>& locations, int i, int finish, int fuel) {
    if (fuel < 0)
      return 0;
    if (dp[i][fuel] != -1)
      return dp[i][fuel];

    int res = i == finish ? 1 : 0;
    for (int j = 0; j < locations.size(); ++j) {
      if (j == i)
        continue;
      res +=
          count(locations, j, finish, fuel - abs(locations[i] - locations[j]));
      res %= kMod;
    }

    return dp[i][fuel] = res;
  }
};
