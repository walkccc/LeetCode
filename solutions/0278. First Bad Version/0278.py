class Solution:
  def firstBadVersion(self, n: int) -> int:
    l = 1
    r = n

    while l < r:
      m = (l + r) // 2
      if isBadVersion(m):
        r = m
      else:
        l = m + 1

    return l
