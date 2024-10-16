class Solution:
  def maxTastiness(
      self,
      price: list[int],
      tastiness: list[int],
      maxAmount: int,
      maxCoupons: int,
  ) -> int:
    n = len(price)
    # dp[i][j][k] := the maximum tastiness of first i price with j amount of
    # money and k coupons
    dp = [[[0] * (maxCoupons + 1)
           for j in range(maxAmount + 1)]
          for i in range(n + 1)]

    for i in range(1, n + 1):
      # 1-indexed
      currPrice = price[i - 1]
      currTastiness = tastiness[i - 1]
      for amount in range(maxAmount + 1):
        for coupon in range(maxCoupons + 1):
          # 1. Don't buy, the tastiness will be the same as the first i - 1
          # price.
          dp[i][amount][coupon] = dp[i - 1][amount][coupon]

          # 2. Buy without coupon if have enough money.
          if amount >= currPrice:
            dp[i][amount][coupon] = max(
                dp[i][amount][coupon],
                dp[i - 1][amount - currPrice][coupon] + currTastiness)

          # 3. Buy with coupon if have coupon and enough money.
          if coupon > 0 and amount >= currPrice // 2:
            dp[i][amount][coupon] = max(
                dp[i][amount][coupon],
                dp[i - 1][amount - currPrice // 2][coupon - 1] + currTastiness)

    return dp[n][maxAmount][maxCoupons]
