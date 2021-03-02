class Solution:
  def minEatingSpeed(self, piles: List[int], H: int) -> int:
    l = 1
    r = max(piles) + 1

    while l < r:
      m = (l + r) // 2
      hour = 0
      for pile in piles:
        hour += (pile - 1) // m + 1
      if hour > H:
        l = m + 1
      else:
        r = m

    return l
