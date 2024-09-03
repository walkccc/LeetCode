class Solution {
 public:
  bool isMajorityElement(vector<int>& nums, int target) {
    const int n = nums.size();
    const int i = ranges::lower_bound(nums, target) - nums.begin();
    return i + n / 2 < n && nums[i + n / 2] == target;
  }
};
