class Solution:
  def minSteps(self, s: str, t: str) -> int:
    count = collections.Counter(s)
    count.subtract(collections.Counter(t))
    return sum(abs(value) for value in count.values()) // 2
