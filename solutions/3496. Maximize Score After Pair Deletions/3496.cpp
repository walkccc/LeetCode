class Solution {
 public:
  int maxScore(vector<int>& nums) {
    const int n = nums.size();
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (n % 2 == 1)
      return sum - ranges::min(nums);
    int minAdjacentSum = INT_MAX;
    for (int i = 1; i < n; ++i)
      minAdjacentSum = min(minAdjacentSum, nums[i - 1] + nums[i]);
    return sum - minAdjacentSum;
  }
};
