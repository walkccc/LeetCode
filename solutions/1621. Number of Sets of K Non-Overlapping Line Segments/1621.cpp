class Solution {
 public:
  int numberOfSets(int n, int k) {
    this->n = n;
    dp.resize(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    return numberOfSets(0, k, /*drawing=*/false);
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  int n;
  vector<vector<vector<int>>> dp;

  int numberOfSets(int i, int k, bool drawing) {
    if (k == 0)  // Find a way to draw k segments.
      return 1;
    if (i == n)  // Reach the end.
      return 0;
    if (dp[i][k][drawing] != -1)
      return dp[i][k][drawing];
    if (drawing == 1)
      // 1. Keep drawing at i and move to i + 1.
      // 2. Stop at i so decrease k. We can start from i for the next segment.
      return dp[i][k][drawing] = (numberOfSets(i + 1, k, true) +
                                  numberOfSets(i, k - 1, false)) %
                                 kMod;
    // 1. Skip i and move to i + 1.
    // 2. Start at i and move to i + 1.
    return dp[i][k][drawing] = (numberOfSets(i + 1, k, false) +  //
                                numberOfSets(i + 1, k, true)) %
                               kMod;
  }
};
