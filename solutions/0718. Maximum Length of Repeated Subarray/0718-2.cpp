class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    int ans = 0;
    vector<int> dp(n + 1);

    for (int i = m - 1; i >= 0; --i)
      for (int j = 0; j < n; ++j) {  // the order is important
        dp[j] = nums1[i] == nums2[j] ? dp[j + 1] + 1 : 0;
        ans = max(ans, dp[j]);
      }

    return ans;
  }
};
