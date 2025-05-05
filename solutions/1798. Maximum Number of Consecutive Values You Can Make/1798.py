class Solution:
  def getMaximumConsecutive(self, coins: list[int]) -> int:
    ans = 1  # the next value we want to make

    for coin in sorted(coins):
      if coin > ans:
        return ans
      ans += coin

    return ans
