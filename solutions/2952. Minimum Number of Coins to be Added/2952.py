class Solution:
  # Same as 330. Patching Array
  def minimumAddedCoins(self, coins: List[int], target: int) -> int:
    ans = 0
    i = 0  # coins' index
    miss = 1  # the minimum sum in [1, n] we might miss

    coins.sort()

    while miss <= target:
      if i < len(coins) and coins[i] <= miss:
        miss += coins[i]
        i += 1
      else:
        # Greedily add `miss` itself to increase the range from
        # [1, miss) to [1, 2 * miss).
        miss += miss
        ans += 1

    return ans
