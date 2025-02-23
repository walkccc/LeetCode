class Solution:
  def maxDifference(self, s: str) -> int:
    count = collections.Counter(s)
    maxOdd = max((freq for freq in count.values()
                  if freq % 2 == 1), default=0)
    minEven = min((freq for freq in count.values()
                   if freq % 2 == 0), default=len(s))
    return maxOdd - minEven
