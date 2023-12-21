class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    const int n = nums.size();
    ranges::sort(nums);
    return max(nums[n - 1] * nums[0] * nums[1],
               nums[n - 1] * nums[n - 2] * nums[n - 3]);
  }
};
