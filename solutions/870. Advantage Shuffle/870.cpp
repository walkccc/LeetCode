class Solution {
 public:
  vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    multiset<int> set{nums1.begin(), nums1.end()};

    for (int i = 0; i < nums2.size(); ++i) {
      const auto p =
          *set.rbegin() <= nums2[i] ? set.begin() : set.upper_bound(nums2[i]);
      nums1[i] = *p;
      set.erase(p);
    }

    return nums1;
  }
};
