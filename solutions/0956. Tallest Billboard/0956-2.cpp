class Solution {
 public:
  int tallestBillboard(vector<int>& rods) {
    const int sum = accumulate(begin(rods), end(rods), 0);
    // dp[i] := max min-height of using rods so far to pile two piles that have
    // height difference i
    vector<int> dp(sum + 1, -1);
    dp[0] = 0;

    for (const int h : rods) {
      vector<int> prev(dp);
      for (int i = 0; i <= sum - h; ++i) {
        if (prev[i] < 0)
          continue;
        // don't use this rod
        dp[i] = max(dp[i], prev[i]);
        // put on the taller pile
        dp[i + h] = max(dp[i + h], prev[i]);
        // put on the shorter pile
        dp[abs(i - h)] = max(dp[abs(i - h)], prev[i] + min(i, h));
      }
    }

    return dp[0];
  }
};
