class Solution {
  public int maxTastiness(int[] price, int[] tastiness, int maxAmount, int maxCoupons) {
    // dp[j][k] := the maximum tastiness of price so far with j amount of money and k
    // coupons
    int[][] dp = new int[maxAmount + 1][maxCoupons + 1];

    for (int i = 0; i < price.length; ++i)
      for (int j = maxAmount; j >= price[i] / 2; --j)
        for (int k = maxCoupons; k >= 0; --k) {
          final int buyWithCoupon = k == 0 ? 0 : dp[j - price[i] / 2][k - 1] + tastiness[i];
          final int buyWithoutCoupon = j < price[i] ? 0 : dp[j - price[i]][k] + tastiness[i];
          dp[j][k] = Math.max(dp[j][k], Math.max(buyWithCoupon, buyWithoutCoupon));
        }

    return dp[maxAmount][maxCoupons];
  }
}
