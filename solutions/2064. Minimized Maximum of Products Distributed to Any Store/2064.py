class Solution:
  def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
    l = 1
    r = max(quantities)

    def numOfStores(x: int) -> int:
      return sum((q - 1) // x + 1 for q in quantities)

    while l < r:
      m = (l + r) // 2
      if numOfStores(m) <= n:
        r = m
      else:
        l = m + 1

    return l
