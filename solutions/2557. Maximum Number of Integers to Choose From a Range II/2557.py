class Solution:
  def maxCount(self, banned: list[int], n: int, maxSum: int) -> int:
    bannedSet = set(banned)
    l = 1
    r = n

    while l < r:
      m = (l + r + 1) // 2
      if self._getSum(bannedSet, m) > maxSum:
        r = m - 1
      else:
        l = m

    return l - sum(b <= l for b in banned)

  # Returns sum([1..m]) - sum(bannedSet).
  def _getSum(self, bannedSet: set[int], m: int) -> int:
    return m * (m + 1) // 2 - sum(b for b in bannedSet if b <= m)
