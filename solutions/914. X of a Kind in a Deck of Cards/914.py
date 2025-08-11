class Solution:
  def hasGroupsSizeX(self, deck: list[int]) -> bool:
    count = collections.Counter(deck)
    return functools.reduce(math.gcd, count.values()) >= 2
