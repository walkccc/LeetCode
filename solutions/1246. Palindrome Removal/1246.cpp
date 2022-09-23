class Solution {
 public:
  int minimumMoves(vector<int>& arr) {
    const int n = arr.size();
    // dp[i][j] := min # of moves to remove all numbers from arr[i..j]
    vector<vector<int>> dp(n, vector<int>(n, n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int i = 0; i + 1 < n; ++i)
      dp[i][i + 1] = arr[i] == arr[i + 1] ? 1 : 2;

    for (int d = 2; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        // remove arr[i] and arr[j] within the move of
        // removing arr[i + 1..j - 1]
        if (arr[i] == arr[j])
          dp[i][j] = dp[i + 1][j - 1];
        // try all possible partitions
        for (int k = i; k < j; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
      }

    return dp[0][n - 1];
  }
};
