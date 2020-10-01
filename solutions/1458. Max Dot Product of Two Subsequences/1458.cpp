class Solution {
 public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();

    // dp[i][j] := max dot product of two subsequences nums[0..i) and nums2[0..j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        dp[i][j] = max({
          dp[i - 1][j],
          dp[i][j - 1],
          max(0, dp[i - 1][j - 1]) + nums1[i - 1] * nums2[j - 1]
        });

    return dp[m][n];
  }
};