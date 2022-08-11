class Solution {
 public:
  int minMaxGame(vector<int>& nums) {
    if (nums.size() == 1)
      return nums[0];

    vector<int> nextNums;
    for (int i = 0; i < nums.size() / 2; ++i)
      nextNums.push_back(i & 1 ? max(nums[2 * i], nums[2 * i + 1])
                               : min(nums[2 * i], nums[2 * i + 1]));
    return minMaxGame(nextNums);
  }
};
