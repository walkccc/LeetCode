class Solution {
 public:
  int smallestRangeI(vector<int>& nums, int k) {
    const int max = ranges::max(nums);
    const int min = ranges::min(nums);
    return std::max(0, max - min - 2 * k);
  }
};
