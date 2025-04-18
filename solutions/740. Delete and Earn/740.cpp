class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    // Reduce to 198. House Robber
    vector<int> bucket(10001);

    for (const int num : nums)
      bucket[num] += num;

    int prev1 = 0;
    int prev2 = 0;

    for (const int num : bucket) {
      const int dp = max(prev1, prev2 + num);
      prev2 = prev1;
      prev1 = dp;
    }

    return prev1;
  }
};
