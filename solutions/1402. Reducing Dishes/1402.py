class Solution:
  def maxSatisfaction(self, satisfaction: list[int]) -> int:
    ans = 0
    sumSatisfaction = 0

    for s in sorted(satisfaction, reverse=True):
      sumSatisfaction += s
      if sumSatisfaction <= 0:
        return ans
      ans += sumSatisfaction

    return ans
