class Solution {
 public:
  int smallestRangeI(vector<int>& nums, int k) {
    const int mx = ranges::max(nums);
    const int mn = ranges::min(nums);
    return max(0, mx - mn - 2 * k);
  }
};
