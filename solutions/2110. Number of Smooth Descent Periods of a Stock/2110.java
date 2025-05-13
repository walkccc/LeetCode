class Solution {
  public long getDescentPeriods(int[] prices) {
    long ans = 1; // prices[0]
    int dp = 1;

    for (int i = 1; i < prices.length; ++i) {
      if (prices[i] == prices[i - 1] - 1)
        ++dp;
      else
        dp = 1;
      ans += dp;
    }

    return ans;
  }
}
