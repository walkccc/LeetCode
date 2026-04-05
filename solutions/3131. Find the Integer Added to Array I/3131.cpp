class Solution {
 public:
  int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    return ranges::min(nums2) - ranges::min(nums1);
  }
};
