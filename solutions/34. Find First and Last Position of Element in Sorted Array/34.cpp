class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    const int l = ranges::lower_bound(nums, target) - nums.begin();
    if (l == nums.size() || nums[l] != target)
      return {-1, -1};
    const int r = ranges::upper_bound(nums, target) - nums.begin() - 1;
    return {l, r};
  }
};
