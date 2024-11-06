class Solution {
 public:
  int minimumChanges(string s, int k) {
    const int n = s.length();
    // factors[i] := factors of i
    const vector<vector<int>> factors = getFactors(n);
    // cost[i][j] := changes to make s[i..j] a semi-palindrome
    const vector<vector<int>> cost = getCost(s, n, factors);
    // dp[i][j] := the minimum changes to split s[i:] into j valid parts
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, n));

    dp[n][0] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int j = 1; j <= k; ++j)
        for (int l = i + 1; l < n; ++l)
          dp[i][j] = min(dp[i][j], dp[l + 1][j - 1] + cost[i][l]);

    return dp[0][k];
  }

 private:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> factors(n + 1);
    for (int i = 1; i <= n; ++i)
      factors[i].push_back(1);
    for (int d = 2; d < n; ++d)
      for (int i = d * 2; i <= n; i += d)
        factors[i].push_back(d);
    return factors;
  }

  vector<vector<int>> getCost(const string& s, int n,
                              const vector<vector<int>>& factors) {
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        const int length = j - i + 1;
        int minCost = length;
        for (const int d : factors[length])
          minCost = min(minCost, getCost(s, i, j, d));
        cost[i][j] = minCost;
      }
    return cost;
  }

  // Returns the cost to make s[i..j] a semi-palindrome of `d`.
  int getCost(const string& s, int i, int j, int d) {
    int cost = 0;
    for (int offset = 0; offset < d; ++offset) {
      int l = i + offset;
      int r = j - d + 1 + offset;
      while (l < r) {
        if (s[l] != s[r])
          ++cost;
        l += d;
        r -= d;
      }
    }
    return cost;
  }
};
