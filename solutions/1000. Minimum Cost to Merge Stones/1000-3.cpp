class Solution {
 public:
  int mergeStones(vector<int>& stones, int k) {
    const int n = stones.size();
    if ((n - 1) % (k - 1))
      return -1;

    this->k = k;

    // dp[i][j] := the minimum cost to merge stones[i..j]
    dp.resize(n, vector<int>(n, kMax));
    prefix.resize(n + 1);

    partial_sum(stones.begin(), stones.end(), prefix.begin() + 1);

    const int cost = mergeStones(stones, 0, n - 1);
    return cost == kMax ? -1 : cost;
  }

 private:
  static constexpr int kMax = 1'000'000'000;
  int k;
  vector<vector<int>> dp;
  vector<int> prefix;

  int mergeStones(const vector<int>& stones, int i, int j) {
    if (j - i + 1 < k)
      return 0;
    if (dp[i][j] != kMax)
      return dp[i][j];

    for (int m = i; m < j; m += k - 1)
      dp[i][j] = min(dp[i][j],
                     mergeStones(stones, i, m) + mergeStones(stones, m + 1, j));
    if ((j - i) % (k - 1) == 0)
      dp[i][j] += prefix[j + 1] - prefix[i];

    return dp[i][j];
  }
};
