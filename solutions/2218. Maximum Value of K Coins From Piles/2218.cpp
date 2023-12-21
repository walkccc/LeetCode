class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    // dp[i][k] := the maximum value of picking k coins from piles[i..n)
    dp.resize(piles.size(), vector<int>(k + 1));
    return maxValueOfCoins(piles, 0, k);
  }

 private:
  vector<vector<int>> dp;

  int maxValueOfCoins(const vector<vector<int>>& piles, int i, size_t k) {
    if (i == piles.size() || k == 0)
      return 0;
    if (dp[i][k])
      return dp[i][k];

    // Pick no coins from the current pile.
    int ans = maxValueOfCoins(piles, i + 1, k);
    int val = 0;  // the coins picked from the current pile

    // Try to pick 1, 2, ..., k coins from the current pile.
    for (int j = 0; j < min(piles[i].size(), k); ++j) {
      val += piles[i][j];
      ans = max(ans, val + maxValueOfCoins(piles, i + 1, k - j - 1));
    }

    return dp[i][k] = ans;
  }
};
