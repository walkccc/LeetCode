class Solution {
 public:
  int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
    // After removing two elements from nums1, either nums1[0], nums1[1], or
    // nums1[2] will persist. Therefore, the difference between nums1 (with two
    // elements removed) and nums2 is represented by nums2[0] - nums1[i], where
    // 0 <= i <= 2.
    int ans = INT_MAX;

    ranges::sort(nums1);
    ranges::sort(nums2);

    for (int i = 0; i < 3; ++i) {
      const int inc = nums2[0] - nums1[i];
      if (isValidDiff(nums1, nums2, inc))
        ans = min(ans, inc);
    }

    return ans;
  }

 private:
  // Returns true if it's possible to increase nums1 (with two elements removed)
  // by `inc` to nums2.
  bool isValidDiff(const vector<int>& nums1, const vector<int>& nums2,
                   int inc) {
    int removed = 0;
    int i = 0;  // nums2's index

    for (const int num : nums1)
      if (num + inc == nums2[i]) {
        if (++i == nums2.size())
          break;
      } else {
        ++removed;
      }

    return removed <= 2;
  }
};
