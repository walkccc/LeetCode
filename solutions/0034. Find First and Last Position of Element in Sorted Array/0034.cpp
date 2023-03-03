class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    const int l = lower_bound(begin(nums), end(nums), target) - begin(nums);
    if (l == nums.size() || nums[l] != target)
      return {-1, -1};
    const int r = upper_bound(begin(nums), end(nums), target) - begin(nums) - 1;
    return {l, r};
  }
};
