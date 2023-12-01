class Solution {
 public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        dp[i][j] = nums1[i - 1] == nums2[j - 1]
                       ? dp[i - 1][j - 1] + 1
                       : max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m][n];
  }
};
