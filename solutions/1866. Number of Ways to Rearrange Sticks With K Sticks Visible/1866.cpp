class Solution {
 public:
  long rearrangeSticks(int n, int k) {
    if (n == k)
      return 1;
    if (k == 0)
      return 0;
    if (dp[n][k])
      return dp[n][k];
    return dp[n][k] = (rearrangeSticks(n - 1, k - 1) +
                       rearrangeSticks(n - 1, k) * (n - 1)) %
                      kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(1001));
};
