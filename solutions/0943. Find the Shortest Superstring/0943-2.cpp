class Solution {
 public:
  string shortestSuperstring(vector<string>& A) {
    const int n = A.size();
    // cost[i][j] := the cost to append A[j] after A[i]
    vector<vector<int>> cost(n, vector<int>(n));
    // dp[s][j] := the minimum cost to visit nodes of s ending in j, s is a
    // binary Value, e.g. dp[6][2] means the minimum cost to visit {1, 2} ending
    // in 2 (6 = 2^1 + 2^2)
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    // parent[s][j] := the parent of "nodes of s ending in j"
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));

    // Returns the cost to append b after a.
    auto getCost = [](const string& a, const string& b) {
      int cost = b.length();
      const int minLength = min(a.length(), b.length());
      for (int k = 1; k <= minLength; ++k)
        if (a.substr(a.length() - k) == b.substr(0, k))
          cost = b.length() - k;
      return cost;
    };

    // Pre-calculate the `cost` array to save time.
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        cost[i][j] = getCost(A[i], A[j]);
        cost[j][i] = getCost(A[j], A[i]);
      }

    for (int i = 0; i < n; ++i)
      dp[1 << i][i] = A[i].length();

    // Enumerate all the states ending in different nodes.
    for (int s = 1; s < (1 << n); ++s)
      for (int i = 0; i < n; ++i) {
        if ((s & (1 << i)) == 0)
          continue;
        for (int j = 0; j < n; ++j)
          if (dp[s - (1 << i)][j] + cost[j][i] < dp[s][i]) {
            dp[s][i] = dp[s - (1 << i)][j] + cost[j][i];
            parent[s][i] = j;
          }
      }

    string ans;
    const vector<int>& dpBack = dp.back();
    int j = distance(dpBack.begin(), ranges::min_element(dpBack));
    int s = (1 << n) - 1;  // 2^0 + 2^1 + ... + 2^(n - 1)

    // Traverse back to build the string.
    while (s > 0) {
      const int i = parent[s][j];
      if (i == -1)
        ans = A[j] + ans;
      else
        ans = A[j].substr(A[j].length() - cost[i][j]) + ans;
      s -= 1 << j;
      j = i;
    }

    return ans;
  }
};
