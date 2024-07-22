class Solution:
  def maxTastiness(self, price: List[int], tastiness: List[int], maxAmount: int, maxCoupons: int) -> int:
    # dp[j][k] := the maximum tastiness of price so far with j amount of money and k coupons
    dp = [[0] * (maxCoupons + 1) for _ in range(maxAmount + 1)]

    for p, t in zip(price, tastiness):
      for j in range(maxAmount, p // 2 - 1, -1):
        for k in range(maxCoupons, -1, -1):
          buyWithCoupon = 0 if k == 0 else dp[j - p // 2][k - 1] + t
          buyWithoutCoupon = 0 if j < p else dp[j - p][k] + t
          dp[j][k] = max(dp[j][k], buyWithCoupon, buyWithoutCoupon)

    return dp[maxAmount][maxCoupons]
