class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    ranges::sort(nums, greater<>());

    const int maxNum = ranges::max(nums);
    // dp[i] := the longest square streak starts with i
    vector<int> dp(maxNum + 1);

    for (const int num : nums) {
      dp[num] = 1;
      const long squaredNum = static_cast<long>(num) * num;
      if (squaredNum <= maxNum)
        dp[num] += dp[squaredNum];
    }

    const int ans = ranges::max(dp);
    return ans < 2 ? -1 : ans;
  }
};
