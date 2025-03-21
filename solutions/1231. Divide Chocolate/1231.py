class Solution:
  def maximizeSweetness(self, sweetness: list[int], k: int) -> int:
    l = len(sweetness) // (k + 1)
    r = sum(sweetness) // (k + 1)

    def canEat(m: int) -> bool:
      """
      Returns True if can eat m sweetness (the minimum sweetness of each piece).
      """
      pieces = 0
      summ = 0  # the running sum
      for s in sweetness:
        summ += s
        if summ >= m:
          pieces += 1
          summ = 0
      return pieces > k

    while l < r:
      m = (l + r) // 2
      if canEat(m):
        l = m + 1
      else:
        r = m

    return l if canEat(l) else l - 1
