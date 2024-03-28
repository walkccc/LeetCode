class Solution {
 public:
  int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    return dfs(nums1, nums2, vector<int>(1 << nums2.size(), INT_MAX), 0, 0);
  }

 private:
  int dfs(const vector<int>& nums1, const vector<int>& nums2, vector<int>&& dp,
          int i, int mask) {
    if (i == nums1.size())
      return 0;
    if (dp[mask] < INT_MAX)
      return dp[mask];

    for (int j = 0; j < nums2.size(); ++j)
      if ((mask >> j & 1) == 0)
        dp[mask] = min(dp[mask],  //
                       (nums1[i] ^ nums2[j]) +
                           dfs(nums1, nums2, move(dp), i + 1, mask | 1 << j));

    return dp[mask];
  }
};
