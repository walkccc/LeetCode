class Solution:
  def maximumTastiness(self, price: List[int], k: int) -> int:
    l = 0
    r = max(price) - min(price) + 1

    price.sort()

    # Returns the max size basket of m tastiness.
    def maxSize(m: int) -> int:
      size = 0
      prevPrice = -m
      for p in price:
        if p >= prevPrice + m:
          prevPrice = p
          size += 1
      return size

    while l < r:
      m = (l + r) // 2
      if maxSize(m) >= k:
        l = m + 1
      else:
        r = m

    return l - 1
