class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    nums.erase(std::unique(begin(nums), end(nums)), end(nums));
    sort(begin(nums), end(nums), greater<>());

    const int maxNum = *max_element(begin(nums), end(nums));
    // dp[i] := longest square streak starts with i
    vector<int> dp(maxNum + 1);

    for (const int num : nums) {
      dp[num] = 1;
      const long squaredNum = static_cast<long>(num) * num;
      if (squaredNum <= maxNum)
        dp[num] += dp[squaredNum];
    }

    const int ans = *max_element(begin(dp), end(dp));
    return ans < 2 ? -1 : ans;
  }
};
