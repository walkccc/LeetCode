class Solution {
 public:
  int returnToBoundaryCount(vector<int>& nums) {
    partial_sum(nums.begin(), nums.end(), nums.begin());
    return ranges::count(nums, 0);
  }
};
