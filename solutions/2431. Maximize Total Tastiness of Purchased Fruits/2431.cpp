class Solution {
 public:
  int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount,
                   int maxCoupons) {
    const int n = price.size();
    // dp[i][j][k] := the maximum tastiness of first i price with j amount of
    // money and k coupons
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(maxAmount + 1, vector<int>(maxCoupons + 1)));

    for (int i = 1; i <= n; ++i) {
      // 1-indexed
      const int currPrice = price[i - 1];
      const int currTastiness = tastiness[i - 1];
      for (int amount = 0; amount <= maxAmount; ++amount) {
        for (int coupon = 0; coupon <= maxCoupons; ++coupon) {
          // 1. Don't buy, the tastiness will be the same as the first i - 1
          // price.
          dp[i][amount][coupon] = dp[i - 1][amount][coupon];

          // 2. Buy without coupon if have enough money.
          if (amount >= currPrice)
            dp[i][amount][coupon] =
                max(dp[i][amount][coupon],
                    dp[i - 1][amount - currPrice][coupon] + currTastiness);

          // 3. Buy with coupon if have coupon and enough money.
          if (coupon > 0 && amount >= currPrice / 2)
            dp[i][amount][coupon] = max(
                dp[i][amount][coupon],
                dp[i - 1][amount - currPrice / 2][coupon - 1] + currTastiness);
        }
      }
    }

    return dp[n][maxAmount][maxCoupons];
  }
};
