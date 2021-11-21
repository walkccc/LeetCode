class Solution {
 public:
  int superEggDrop(int K, int N) {
    // dp[k][n] := min # of moves to know F with k eggs and n floors
    dp.resize(K + 1, vector<int>(N + 1, -1));
    return drop(K, N);
  }

 private:
  vector<vector<int>> dp;

  int drop(int k, int n) {
    if (k == 0)  // no eggs -> done
      return 0;
    if (k == 1)  // one egg -> drop from 1-th floor to n-th floor
      return n;
    if (n == 0)  // no floor -> done
      return 0;
    if (n == 1)  // one floor -> drop from that floor
      return 1;
    if (dp[k][n] != -1)
      return dp[k][n];

    dp[k][n] = INT_MAX;

    for (int i = 1; i <= n; ++i) {
      const int broken = drop(k - 1, i - 1);
      const int unbroken = drop(k, n - i);
      dp[k][n] = min(dp[k][n], 1 + max(broken, unbroken));
    }

    return dp[k][n];
  }
};
