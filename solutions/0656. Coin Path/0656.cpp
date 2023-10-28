class Solution {
 public:
  vector<int> cheapestJump(vector<int>& coins, int maxJump) {
    if (coins.back() == -1)
      return {};

    const int n = coins.size();
    vector<int> next(n, -1);

    // dp[i] := min cost to jump from i to n - 1
    dp.resize(n, INT_MAX);
    cheapestJump(coins, maxJump, 0, next);

    if (dp[0] == INT_MAX)
      return {};
    return constructPath(next, 0);
  }

 private:
  vector<int> dp;

  int cheapestJump(const vector<int>& coins, int maxJump, int i,
                   vector<int>& next) {
    if (i == coins.size() - 1)
      return dp[i] = coins[i];
    if (dp[i] < INT_MAX)
      return dp[i];
    if (coins[i] == -1)
      return INT_MAX;

    for (int j = i + 1; j <= i + maxJump && j < coins.size(); ++j) {
      const int res = cheapestJump(coins, maxJump, j, next);
      if (res == INT_MAX)
        continue;
      const int cost = coins[i] + res;
      if (cost < dp[i]) {
        dp[i] = cost;
        next[i] = j;
      }
    }

    return dp[i];
  }

  vector<int> constructPath(const vector<int>& next, int i) {
    vector<int> ans;
    while (i != -1) {
      ans.push_back(i + 1);  // 1-indexed
      i = next[i];
    }
    return ans;
  }
};
