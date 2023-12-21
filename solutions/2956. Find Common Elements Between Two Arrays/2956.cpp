class Solution {
 public:
  vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    const unordered_set<int> nums1Set{nums1.begin(), nums1.end()};
    const unordered_set<int> nums2Set{nums2.begin(), nums2.end()};
    const int ans1 = ranges::count_if(
        nums1, [&nums2Set](int num) { return nums2Set.count(num); });
    const int ans2 = ranges::count_if(
        nums2, [&nums1Set](int num) { return nums1Set.count(num); });
    return {ans1, ans2};
  }
};
