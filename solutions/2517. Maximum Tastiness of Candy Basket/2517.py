class Solution:
  def maximumTastiness(self, price: list[int], k: int) -> int:
    price.sort()

    def numBaskets(m: int) -> int:
      """Returns the number of baskets we can pick for m tastiness."""
      baskets = 0
      prevPrice = -m
      for p in price:
        if p >= prevPrice + m:
          prevPrice = p
          baskets += 1
      return baskets

    l = bisect.bisect_left(range(max(price) - min(price) + 1), True,
                           key=lambda m: numBaskets(m) < k)
    return l - 1
