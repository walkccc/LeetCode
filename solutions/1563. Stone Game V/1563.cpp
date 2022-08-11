class Solution {
 public:
  int stoneGameV(vector<int>& stoneValue) {
    const int n = stoneValue.size();
    // dp[i][j] := max score that Alice can obtain from stoneValue[i..j]
    dp.resize(n, vector<int>(n, INT_MIN));
    prefix.resize(n + 1);

    partial_sum(begin(stoneValue), end(stoneValue), begin(prefix) + 1);
    return stoneGameV(stoneValue, 0, n - 1);
  }

 private:
  vector<vector<int>> dp;
  vector<int> prefix;

  int stoneGameV(const vector<int>& stoneValue, int i, int j) {
    if (i == j)
      return 0;
    if (dp[i][j] > 0)
      return dp[i][j];

    // try all possible partitions
    for (int p = i; p < j; ++p) {
      // sum of stoneValue[i..p]
      const int leftSum = prefix[p + 1] - prefix[i];
      const int throwRight = leftSum + stoneGameV(stoneValue, i, p);
      // sum of stoneValue[p + 1..j]
      const int rightSum = prefix[j + 1] - prefix[p + 1];
      const int throwLeft = rightSum + stoneGameV(stoneValue, p + 1, j);
      if (leftSum < rightSum)  // Bob throws right row
        dp[i][j] = max(dp[i][j], throwRight);
      else if (leftSum > rightSum)  // Bob throws left row
        dp[i][j] = max(dp[i][j], throwLeft);
      else  // Alice decide which row to throw
        dp[i][j] = max({dp[i][j], throwLeft, throwRight});
    }

    return dp[i][j];
  }
};
