class Solution:
  def maximumCandies(self, candies: List[int], k: int) -> int:
    l = 1
    r = sum(candies) // k

    def numChildren(m: int) -> bool:
      return sum(c // m for c in candies) 

    while l < r:
      m = (l + r) // 2
      if numChildren(m) < k:
        r = m
      else:
        l = m + 1

    return l if numChildren(l) >= k else l - 1
