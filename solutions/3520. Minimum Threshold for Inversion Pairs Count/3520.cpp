class Solution {
 public:
  int minThreshold(vector<int>& nums, int k) {
    const int mx = ranges::max(nums);
    int l = 0;
    int r = mx + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (countInversionPairs(nums, k, m))
        r = m;
      else
        l = m + 1;
    }

    return l > mx ? -1 : l;
  }

 private:
  bool countInversionPairs(const vector<int>& nums, int k, int threshold) {
    int inversionCount = 0;
    vector<int> sortedNums;

    for (const int num : nums) {
      const auto lower = ranges::upper_bound(sortedNums, num);
      const auto upper = ranges::upper_bound(sortedNums, num + threshold);
      inversionCount += upper - lower;
      sortedNums.insert(lower, num);
    }

    return inversionCount >= k;
  }
};
