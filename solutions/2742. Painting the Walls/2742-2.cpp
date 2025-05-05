class Solution {
 public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    constexpr int kMax = 500'000'000;
    const int n = cost.size();
    // dp[i] := the minimum cost to paint i walls by the painters so far
    vector<int> dp(n + 1, kMax);
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
      for (int walls = n; walls > 0; --walls)
        dp[walls] = min(dp[walls], dp[max(walls - time[i] - 1, 0)] + cost[i]);

    return dp[n];
  }
};
