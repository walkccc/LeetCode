class Solution {
 public:
  int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    return dfs(nums1, nums2, vector<int>(1 << nums2.size(), INT_MAX), 0, 0);
  }

 private:
  int dfs(const vector<int>& A, const vector<int>& B, vector<int>&& dp, int i,
          int mask) {
    if (i == A.size())
      return 0;
    if (dp[mask] < INT_MAX)
      return dp[mask];

    for (int j = 0; j < B.size(); ++j)
      if (!(mask >> j & 1))
        dp[mask] = min(dp[mask], (A[i] ^ B[j]) +
                                     dfs(A, B, move(dp), i + 1, mask | 1 << j));

    return dp[mask];
  }
};
