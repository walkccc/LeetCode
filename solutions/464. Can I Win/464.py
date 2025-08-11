class Solution:
  def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
    if desiredTotal <= 0:
      return True

    totalSum = maxChoosableInteger * (maxChoosableInteger + 1) // 2
    if totalSum < desiredTotal:
      return False

    @functools.lru_cache(None)
    def dp(total: int, used: int) -> bool:
      """
      Returns true if the first player can we, where `used` represents the use
      numbers.
      """
      if total <= 0:
        return False
      return any((used >> i & 1) == 0
                 and not dp(total - i, used | 1 << i)
                 for i in range(1, maxChoosableInteger + 1))

    return dp(desiredTotal, 0)
