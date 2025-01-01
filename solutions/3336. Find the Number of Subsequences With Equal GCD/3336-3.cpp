class Solution {
 public:
  int subsequencePairCount(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    const int maxNum = ranges::max(nums);
    // dp[x][y] := the number of disjoint pairs `seq1` and `seq2` of
    // nums so far, where GCD(seq1) == x and GCD(seq2) == y
    vector<vector<int>> dp(maxNum + 1, vector<int>(maxNum + 1));
    dp[0][0] = 1;

    for (const int num : nums) {
      vector<vector<int>> newDp(maxNum + 1, vector<int>(maxNum + 1));
      for (int x = 0; x <= maxNum; ++x)
        for (int y = 0; y <= maxNum; ++y) {
          // 1. Skip `num`.
          newDp[x][y] += dp[x][y];
          newDp[x][y] %= kMod;
          // 2. Pick `num` in the first subsequence.
          const int newX = gcd(x, num);
          newDp[newX][y] += dp[x][y];
          newDp[newX][y] %= kMod;
          // 3. Pick `num` in the second subsequence.
          const int newY = gcd(y, num);
          newDp[x][newY] += dp[x][y];
          newDp[x][newY] %= kMod;
        }
      dp = std::move(newDp);
    }

    int ans = 0;
    for (int g = 1; g <= maxNum; ++g) {
      ans += dp[g][g];
      ans %= kMod;
    }
    return ans;
  }
};
