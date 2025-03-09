class Solution {
 public:
  int specialArray(vector<int>& nums) {
    ranges::sort(nums);

    if (nums[0] >= nums.size())
      return nums.size();

    for (int i = 1; i < nums.size(); ++i) {
      const int count = nums.size() - i;
      if (nums[i - 1] < count && nums[i] >= count)
        return count;
    }

    return -1;
  }
};
