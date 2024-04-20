class Solution {
 public:
  int minDifference(vector<int>& nums) {
    const int n = nums.size();
    if (n < 5)
      return 0;

    int ans = INT_MAX;

    ranges::sort(nums);

    // 1. Change nums[0..i) to nums[i].
    // 2. Change nums[n - 3 + i..n) to nums[n - 4 + i].
    for (int i = 0; i <= 3; ++i)
      ans = min(ans, nums[n - 4 + i] - nums[i]);

    return ans;
  }
};
