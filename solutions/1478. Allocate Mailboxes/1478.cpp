class Solution {
 public:
  int minDistance(vector<int>& houses, int k) {
    const int n = houses.size();
    // dp[i][j] := min distance to allocate i mailboxes in houses[j:]
    dp.resize(k + 1, vector<int>(n, INT_MAX));
    // cost[i][j] := minCost to allocate mailbox between houses[i] and houses[j]
    cost.resize(n, vector<int>(n));

    sort(begin(houses), end(houses));

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        const int median = houses[(i + j) / 2];
        for (int x = i; x <= j; ++x)
          cost[i][j] += abs(houses[x] - median);
      }

    return minDistance(houses, k, 0);
  }

 private:
  constexpr static int kMax = 1e6;
  vector<vector<int>> dp;
  vector<vector<int>> cost;

  int minDistance(const vector<int>& houses, int k, int i) {
    if (k == 0 && i == houses.size())
      return 0;
    if (k == 0 || i == houses.size())
      return kMax;
    if (dp[k][i] != INT_MAX)
      return dp[k][i];

    for (int j = i; j < houses.size(); ++j)
      dp[k][i] = min(dp[k][i], cost[i][j] + minDistance(houses, k - 1, j + 1));

    return dp[k][i];
  }
};
