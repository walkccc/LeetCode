class Solution:
  def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
    prefix = [0] + list(itertools.accumulate(candiesCount))
    return [prefix[t] // c <= d < prefix[t + 1] for t, d, c in queries]
