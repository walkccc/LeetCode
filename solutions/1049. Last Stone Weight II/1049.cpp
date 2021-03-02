class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    const int sum = accumulate(begin(stones), end(stones), 0);
    vector<bool> dp(sum + 1);
    dp[0] = true;
    int s = 0;

    for (int stone : stones)
      for (int w = sum / 2; w > 0; --w) {
        if (w >= stone)
          dp[w] = dp[w] || dp[w - stone];
        if (dp[w])
          s = max(s, w);
      }

    return sum - 2 * s;
  }
};
