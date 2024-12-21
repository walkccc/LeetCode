class Solution {
 public:
  vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    const unordered_set<int> set1{nums1.begin(), nums1.end()};
    const unordered_set<int> set2{nums2.begin(), nums2.end()};
    const int ans1 = ranges::count_if(
        nums1, [&set2](int num) { return set2.contains(num); });
    const int ans2 = ranges::count_if(
        nums2, [&set1](int num) { return set1.contains(num); });
    return {ans1, ans2};
  }
};
