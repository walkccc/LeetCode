class Solution {
 public:
  int minProductSum(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0;

    sort(nums1.begin(), nums1.end());
    sort(nums2.rbegin(), nums2.rend());

    for (int i = 0; i < nums1.size(); ++i)
      ans += nums1[i] * nums2[i];

    return ans;
  }
};
