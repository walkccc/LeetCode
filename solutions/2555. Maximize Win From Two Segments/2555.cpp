class Solution {
 public:
  int maximizeWin(vector<int>& prizePositions, int k) {
    int ans = 0;
    // dp[i] := the maximum number of prizes to choose the first i
    // `prizePositions`
    vector<int> dp(prizePositions.size() + 1);

    for (int i = 0, j = 0; i < prizePositions.size(); ++i) {
      while (prizePositions[i] - prizePositions[j] > k)
        ++j;
      const int covered = i - j + 1;
      dp[i + 1] = max(dp[i], covered);
      ans = max(ans, dp[j] + covered);
    }

    return ans;
  }
};
