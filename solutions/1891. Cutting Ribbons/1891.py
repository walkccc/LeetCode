class Solution:
  def maxLength(self, ribbons: list[int], k: int) -> int:
    def isCutPossible(length: int) -> bool:
      count = 0
      for ribbon in ribbons:
        count += ribbon // length
      return count >= k

    l = 1
    r = sum(ribbons) // k + 1

    while l < r:
      m = (l + r) // 2
      if not isCutPossible(m):
        r = m
      else:
        l = m + 1

    return l - 1
