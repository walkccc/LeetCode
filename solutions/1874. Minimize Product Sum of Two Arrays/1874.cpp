class Solution {
 public:
  int minProductSum(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;

    ranges::sort(nums1);
    ranges::sort(nums2, greater<>());

    for (int i = 0; i < nums1.size(); ++i)
      ans += nums1[i] * nums2[i];

    return ans;
  }
};
