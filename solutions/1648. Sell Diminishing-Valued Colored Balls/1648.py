class Solution:
  def maxProfit(self, inventory: List[int], orders: int) -> int:
    kMod = 1_000_000_007
    ans = 0
    largestCount = 1

    def trapezoid(a: int, b: int) -> int:
      return (a + b) * (a - b + 1) // 2

    for a, b in itertools.pairwise(sorted(inventory, reverse=True) + [0]):
      if a > b:
        # If we are at the last inventory, or inventory[i] > inventory[i + 1].
        # In either case, we will pick inventory[i - largestCount + 1..i].
        pick = a - b
        # We have run out of orders, so we need to recalculate the number of
        # balls that we actually pick for inventory[i - largestCount + 1..i].
        if largestCount * pick >= orders:
          actualPick, remaining = divmod(orders, largestCount)
          return (ans +
                  largestCount * trapezoid(a, a - actualPick + 1) +
                  remaining * (a - actualPick)) % kMod
        ans += largestCount * trapezoid(a, a - pick + 1)
        ans %= kMod
        orders -= largestCount * pick
      largestCount += 1
