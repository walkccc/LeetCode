class Solution {
 public:
  int stoneGameVII(vector<int>& stones) {
    const int n = stones.size();
    // dp[i][j] := max score you can get more than your opponent in stones[i..j]
    dp.resize(n, vector<int>(n));
    prefix.resize(n + 1);

    partial_sum(begin(stones), end(stones), begin(prefix) + 1);
    return stoneGameVII(stones, 0, n - 1);
  }

 private:
  vector<vector<int>> dp;
  vector<int> prefix;

  int stoneGameVII(const vector<int>& stones, int i, int j) {
    if (i == j)
      return 0;
    if (dp[i][j] > 0)
      return dp[i][j];

    dp[i][j] =
        max({dp[i][j],
             // remove stones[i], so get sum of stones[i + 1..j]
             prefix[j + 1] - prefix[i + 1] - stoneGameVII(stones, i + 1, j),
             // remove stones[j], so get sum of stones[i..j - 1]
             prefix[j] - prefix[i] - stoneGameVII(stones, i, j - 1)});

    return dp[i][j];
  }
};
