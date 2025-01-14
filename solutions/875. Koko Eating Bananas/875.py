class Solution:
  def minEatingSpeed(self, piles: list[int], h: int) -> int:
    def eatHours(m: int) -> bool:
      """Returns the hours to eat all the piles with speed m."""
      return sum((pile - 1) // m + 1 for pile in piles)
    l = 1
    r = max(piles)
    return bisect.bisect_left(range(l, r), True,
                              key=lambda m: eatHours(m) <= h) + l
