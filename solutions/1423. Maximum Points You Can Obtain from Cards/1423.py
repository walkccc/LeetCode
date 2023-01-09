class Solution:
  def maxScore(self, cardPoints: List[int], k: int) -> int:
    n = len(cardPoints)
    summ = sum(cardPoints)
    windowSum = sum(cardPoints[:n - k])
    ans = summ - windowSum

    for i in range(k):
      windowSum -= cardPoints[i]
      windowSum += cardPoints[i + n - k]
      ans = max(ans, summ - windowSum)

    return ans
