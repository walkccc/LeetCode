class Solution {
 public:
  int minLargest(vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    // dp[i][j] := the minimum largest number for the first i nums1 and the
    // first j nums2
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i <= m; ++i)
      for (int j = 0; j <= n; ++j) {
        if (i > 0)
          dp[i][j] = min(dp[i][j], f(dp[i - 1][j], nums1[i - 1]));
        if (j > 0)
          dp[i][j] = min(dp[i][j], f(dp[i][j - 1], nums2[j - 1]));
      }

    return dp[m][n];
  }

 private:
  // Returns the next number to fill in the array based on the previous number
  // and the current number.
  int f(int prev, int num) {
    return prev + (prev % 2 == num ? 2 : 1);
  }
};
