class Solution {
 public:
  int smallestRangeI(vector<int>& nums, int k) {
    const int max = *max_element(begin(nums), end(nums));
    const int min = *min_element(begin(nums), end(nums));
    return std::max(0, max - min - 2 * k);
  }
};
