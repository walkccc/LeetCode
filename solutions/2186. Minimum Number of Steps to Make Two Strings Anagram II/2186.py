class Solution:
  def minSteps(self, s: str, t: str) -> int:
    count = Counter(s)
    count.subtract(Counter(t))
    return sum([abs(c) for c in count.values()])
