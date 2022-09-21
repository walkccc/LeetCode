class Solution:
  def maxScoreSightseeingPair(self, A: List[int]) -> int:
    ans = 0
    bestPrev = 0

    for a in A:
      ans = max(ans, a + bestPrev)
      bestPrev = max(bestPrev, a) - 1

    return ans
