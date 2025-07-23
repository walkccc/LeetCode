class Solution {
 public:
  int largestPerimeter(vector<int>& nums) {
    ranges::sort(nums);

    for (int i = nums.size() - 1; i > 1; --i)
      if (nums[i - 2] + nums[i - 1] > nums[i])
        return nums[i - 2] + nums[i - 1] + nums[i];

    return 0;
  }
};
