class Solution:
  def hasGroupsSizeX(self, deck: List[int]) -> bool:
    count = collections.Counter(deck)
    return functools.reduce(math.gcd, count.values()) >= 2
