class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> dp(n);
    int maxLength = 0;
    int prev = 0;  // dp[i - 1][j - 1]

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        const int cache = dp[j];
        if (i == 0 || j == 0 || matrix[i][j] == '0')
          dp[j] = matrix[i][j] == '1' ? 1 : 0;
        else
          dp[j] = min({prev, dp[j], dp[j - 1]}) + 1;
        maxLength = max(maxLength, dp[j]);
        prev = cache;
      }

    return maxLength * maxLength;
  }
};
