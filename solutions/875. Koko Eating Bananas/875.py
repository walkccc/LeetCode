class Solution:
  def minEatingSpeed(self, piles: list[int], h: int) -> int:
    def eatHours(m: int) -> bool:
      """Returns True if Koko can eat all piles with speed m."""
      return sum((pile - 1) // m + 1 for pile in piles) <= h
    return bisect.bisect_left(range(1, max(piles)), True,
                              key=lambda m: eatHours(m)) + 1
