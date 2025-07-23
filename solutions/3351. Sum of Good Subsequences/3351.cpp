class Solution {
 public:
  int sumOfGoodSubsequences(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int maxNum = ranges::max(nums);
    // endsIn[i] := the number of good subsequences ending in i
    vector<long> endsIn(maxNum + 3);
    // dp[i] := the sum of good subsequences ending in i
    vector<long> dp(maxNum + 3);

    for (const int num : nums) {
      const long seqsToAppend = 1 + endsIn[num] + endsIn[num + 2];
      dp[num + 1] =
          (seqsToAppend * num + (dp[num + 1] + dp[num] + dp[num + 2])) % kMod;
      endsIn[num + 1] = (endsIn[num + 1] + seqsToAppend) % kMod;
    }

    return accumulate(dp.begin(), dp.end(), 0,
                      [&](int acc, int d) { return (acc + d) % kMod; });
  }
};
