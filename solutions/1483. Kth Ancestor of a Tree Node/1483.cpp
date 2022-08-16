class TreeAncestor {
 public:
  TreeAncestor(int n, vector<int>& parent)
      : maxLevel(32 - __builtin_clz(n)), dp(n, vector<int>(maxLevel)) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < maxLevel; ++j)
        if (j == 0)  // node i's 2^0 ancestor is its direct parent
          dp[i][j] = parent[i];
        else if (dp[i][j - 1] == -1)  // no such ancestor
          dp[i][j] = -1;
        else  // A(i, 2^j) = A(A(i, 2^{j - 1}), 2^{j - 1})
          dp[i][j] = dp[dp[i][j - 1]][j - 1];
  }

  int getKthAncestor(int node, int k) {
    for (int j = 0; j < maxLevel && node != -1; ++j)
      if (k & 1 << j)
        node = dp[node][j];
    return node;
  }

 private:
  const int maxLevel;
  vector<vector<int>> dp;  // dp[i][j] := node i's 2^j-th ancestor
};
