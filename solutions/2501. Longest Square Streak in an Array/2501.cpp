class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    sort(nums.rbegin(), nums.rend());

    const int maxNum = *max_element(nums.begin(), nums.end());
    // dp[i] := longest square streak starts with i
    vector<int> dp(maxNum + 1);

    for (const int num : nums) {
      dp[num] = 1;
      const long squaredNum = static_cast<long>(num) * num;
      if (squaredNum <= maxNum)
        dp[num] += dp[squaredNum];
    }

    const int ans = *max_element(dp.begin(), dp.end());
    return ans < 2 ? -1 : ans;
  }
};
