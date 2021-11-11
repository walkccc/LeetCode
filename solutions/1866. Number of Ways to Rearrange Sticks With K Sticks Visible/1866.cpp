class Solution {
 public:
  int rearrangeSticks(int n, int k) {
    if (n == k)
      return 1;
    if (k == 0)
      return 0;
    if (dp[n][k])
      return dp[n][k];

    return dp[n][k] = ((long)rearrangeSticks(n - 1, k - 1) +
                       (long)rearrangeSticks(n - 1, k) * (n - 1)) %
                      kMod;
  }

 private:
  const int kMod = 1e9 + 7;
  vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(1001));
};
