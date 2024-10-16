class Solution:
  def maximumTastiness(self, price: list[int], k: int) -> int:
    price.sort()

    def cantPick(m: int) -> bool:
      """Returns True if we can't pick k distinct candies for m tastiness."""
      baskets = 0
      prevPrice = -m
      for p in price:
        if p >= prevPrice + m:
          prevPrice = p
          baskets += 1
      return baskets < k

    l = bisect.bisect_left(range(max(price) - min(price) + 1), True,
                           key=lambda m: cantPick(m))
    return l - 1
