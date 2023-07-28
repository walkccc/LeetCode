class Solution {
 public:
  int smallestRangeI(vector<int>& nums, int k) {
    const int max = *max_element(nums.begin(), nums.end());
    const int min = *min_element(nums.begin(), nums.end());
    return std::max(0, max - min - 2 * k);
  }
};
