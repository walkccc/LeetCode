class Solution:
  def minSteps(self, s: str, t: str) -> int:
    count = collections.Counter(s)
    count.subtract(collections.Counter(t))
    return sum([abs(c) for c in count.values()])
