class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    const int mini = min(nums1.back(), nums2.back());
    const int maxi = max(nums1.back(), nums2.back());
    // the number of the minimum operations, where nums1[n - 1] is not swapped
    // with nums2[n - 1]
    int dp1 = 0;
    // the number of the minimum operations, where nums1[n - 1] is swapped with
    // nums2[n - 1]
    int dp2 = 0;

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
