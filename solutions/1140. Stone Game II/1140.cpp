class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    const int n = piles.size();
    // dp[i][j] := the maximum number of stones Alice can get with piles[i:] and
    // M = j
    dp.resize(n, vector<int>(n));
    // suffixSum[i] := the sum of piles[i:]
    suffixSum = piles;

    for (int i = n - 2; i >= 0; --i)
      suffixSum[i] += suffixSum[i + 1];

    return stoneGameII(0, 1);
  }

 private:
  vector<vector<int>> dp;
  vector<int> suffixSum;

  int stoneGameII(int i, int M) {
    if (i + 2 * M >= dp.size())
      return suffixSum[i];
    if (dp[i][M])
      return dp[i][M];

    int opponent = suffixSum[i];

    for (int X = 1; X <= 2 * M; ++X)
      opponent = min(opponent, stoneGameII(i + X, max(M, X)));

    return dp[i][M] = suffixSum[i] - opponent;
  }
};
