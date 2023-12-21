class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    const int n = piles.size();
    vector<int> dp = piles;

    for (int d = 1; d < n; ++d)
      for (int j = n - 1; j - d >= 0; --j) {
        const int i = j - d;
        dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
      }

    return dp[n - 1] > 0;
  }
};
