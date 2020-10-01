class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    const int n = piles.size();

    vector<int> dp = piles;

    for (int d = 1; d < n; ++d)
      for (int i = n - d - 1; i >= 0; --i)
        dp[i + d] = max(piles[i] - dp[i + d], piles[i + d] - dp[i + d - 1]);

    return dp[n - 1] > 0;
  }
};