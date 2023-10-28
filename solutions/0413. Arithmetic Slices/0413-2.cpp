class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int ans = 0;
    int dp = 0;  // # of arithmetic slices ending at index i

    for (int i = 2; i < nums.size(); ++i)
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        ans += ++dp;
      else
        dp = 0;

    return ans;
  }
};
