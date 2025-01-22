class Solution:
  def maxScoreSightseeingPair(self, values: list[int]) -> int:
    ans = 0
    bestPrev = 0

    for value in values:
      ans = max(ans, value + bestPrev)
      bestPrev = max(bestPrev, value) - 1

    return ans
