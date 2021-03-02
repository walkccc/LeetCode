class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    for (const int num : nums)
      if (num != 0)
        nums[i++] = num;

    for (; i < nums.size(); ++i)
      nums[i] = 0;
  }
};
