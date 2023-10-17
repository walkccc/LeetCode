class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    const int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (l == nums.size() || nums[l] != target)
      return {-1, -1};
    const int r =
        upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {l, r};
  }
};
