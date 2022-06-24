class Solution:
  def getDescentPeriods(self, prices: List[int]) -> int:
    ans = 1  # prices[0]
    dp = 1

    for i in range(1, len(prices)):
      if prices[i] == prices[i - 1] - 1:
        dp += 1
      else:
        dp = 1
      ans += dp

    return ans
