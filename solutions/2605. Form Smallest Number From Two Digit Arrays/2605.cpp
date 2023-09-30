class Solution {
 public:
  int minNumber(vector<int>& nums1, vector<int>& nums2) {
    int ans = 89;  // the largest num we can have
    for (const int a : nums1)
      for (const int b : nums2)
        ans = min(ans, a == b ? a : min(a, b) * 10 + max(a, b));
    return ans;
  }
};
