class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    // dp[i][k] := max value of picking k coins from piles[i:]
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

    int ans =
        maxValueOfCoins(piles, i + 1, k);  // pick 0 coins from current pile
    int val = 0;                           // coins picked from current pile

    // try to pick 1, 2, ..., k coins from current pile
    for (int j = 0; j < min(piles[i].size(), k); ++j) {
      val += piles[i][j];
      ans = max(ans, val + maxValueOfCoins(piles, i + 1, k - j - 1));
    }

    return dp[i][k] = ans;
  }
};
