class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    const int mini = min(nums1.back(), nums2.back());
    const int maxi = max(nums1.back(), nums2.back());
    int dp1 = 0;  // # of min ops with nums1[n - 1] not swapped w/ nums2[n - 1]
    int dp2 = 0;  // # of min ops with nums1[n - 1] swapped w/ nums2[n - 1]

    for (int i = 0; i < n; ++i) {
      const int a = nums1[i];
      const int b = nums2[i];
      if (min(a, b) > mini)
        return -1;
      if (max(a, b) > maxi)
        return -1;
      if (a > nums1.back() || b > nums2.back())
        ++dp1;
      if (a > nums2.back() || b > nums1.back())
        ++dp2;
    }

    return min(dp1, dp2);
  }
};
