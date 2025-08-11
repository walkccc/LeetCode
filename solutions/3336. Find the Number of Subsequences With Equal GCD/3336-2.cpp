class Solution {
 public:
  int subsequencePairCount(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    const int maxNum = ranges::max(nums);
    // dp[i][x][y] := the number of disjoint pairs `seq1` and `seq2` of
    // nums[0..i - 1], where GCD(seq1) == x and GCD(seq2) == y
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(maxNum + 1, vector<int>(maxNum + 1)));
    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i)
      for (int x = 0; x <= maxNum; ++x)
        for (int y = 0; y <= maxNum; ++y) {
          // 1. Skip nums[i].
          dp[i + 1][x][y] += dp[i][x][y];
          dp[i + 1][x][y] %= kMod;
          // 2. Pick nums[i] in the first subsequence.
          const int newX = gcd(x, nums[i]);
          dp[i + 1][newX][y] += dp[i][x][y];
          dp[i + 1][newX][y] %= kMod;
          // 3. Pick nums[i] in the second subsequence.
          const int newY = gcd(y, nums[i]);
          dp[i + 1][x][newY] += dp[i][x][y];
          dp[i + 1][x][newY] %= kMod;
        }

    int ans = 0;
    for (int g = 1; g <= maxNum; ++g) {
      ans += dp[n][g][g];
      ans %= kMod;
    }
    return ans;
  }
};
