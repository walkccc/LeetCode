class Solution {
 public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    constexpr int kMod = 1'000'000'007;
    const int n = locations.size();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(fuel + 1));

    for (int f = 0; f <= fuel; ++f)
      dp[finish][f] = 1;

    for (int f = 0; f <= fuel; ++f)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
          if (i == j)
            continue;
          const int requiredFuel = abs(locations[i] - locations[j]);
          if (requiredFuel <= f) {
            dp[i][f] += dp[j][f - requiredFuel];
            dp[i][f] %= kMod;
          }
        }

    return dp[start][fuel];
  }
};
