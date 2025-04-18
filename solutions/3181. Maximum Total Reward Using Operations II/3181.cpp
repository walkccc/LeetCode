class Solution {
 public:
  // Same as 3180. Maximum Total Reward Using Operations I
  int maxTotalReward(vector<int>& rewardValues) {
    constexpr int kPossibleRewards = 100'000;
    // dp[num] := true if reward `num` is achievable
    bitset<kPossibleRewards> dp;
    dp[0] = true;

    ranges::sort(rewardValues);

    for (const int num : rewardValues) {
      bitset<kPossibleRewards> newBits = dp;
      // Remove the numbers >= the current number.
      newBits <<= kPossibleRewards - num;
      newBits >>= kPossibleRewards - num;
      dp |= newBits << num;
    }

    for (int ans = kPossibleRewards - 1; ans >= 0; --ans)
      if (dp[ans])
        return ans;

    throw;
  }
};
