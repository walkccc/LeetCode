class Solution {
 public:
  int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    vector<int> dp(1 << nums2.size(), INT_MAX);
    return dfs(nums1, nums2, dp, 0, 0);
  }

 private:
  int dfs(const vector<int>& A, const vector<int>& B, vector<int>& dp, int i,
          int mask) {
    if (i == A.size())
      return 0;
    if (dp[mask] < INT_MAX)
      return dp[mask];

    for (int j = 0; j < B.size(); ++j)
      if ((mask & (1 << j)) == 0)
        dp[mask] = min(dp[mask],
                       (A[i] ^ B[j]) + dfs(A, B, dp, i + 1, mask | (1 << j)));

    return dp[mask];
  }
};
