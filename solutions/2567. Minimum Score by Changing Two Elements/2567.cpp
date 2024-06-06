class Solution {
 public:
  int minimizeSum(vector<int>& nums) {
    ranges::sort(nums);
    // Can always change the number to any other number in `nums`, so `low`
    // becomes 0. Thus, rephrase the problem as finding the minimum `high`.
    const int n = nums.size();
    const int highOfChangingTwoMins = nums.back() - nums[2];
    const int highOfChangingTwoMaxs = nums[n - 3] - nums[0];
    const int highOfChangingMinAndMax = nums[n - 2] - nums[1];
    return min({highOfChangingTwoMins, highOfChangingTwoMaxs,
                highOfChangingMinAndMax});
  }
};
