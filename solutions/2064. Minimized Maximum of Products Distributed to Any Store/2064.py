class Solution:
  def minimizedMaximum(self, n: int, quantities: list[int]) -> int:
    l = 1
    r = max(quantities)

    def numStores(m: int) -> int:
      return sum((q - 1) // m + 1 for q in quantities)

    while l < r:
      m = (l + r) // 2
      if numStores(m) <= n:
        r = m
      else:
        l = m + 1

    return l
