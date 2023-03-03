class Solution {
 public:
  vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    multiset<int> set{begin(nums1), end(nums1)};

    for (int i = 0; i < nums2.size(); ++i) {
      const auto p =
          *rbegin(set) <= nums2[i] ? begin(set) : set.upper_bound(nums2[i]);
      nums1[i] = *p;
      set.erase(p);
    }

    return nums1;
  }
};
