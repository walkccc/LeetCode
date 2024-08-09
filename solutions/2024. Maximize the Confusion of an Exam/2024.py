class Solution:
  def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
    ans = 0
    maxCount = 0
    count = collections.Counter()

    l = 0
    for r, c in enumerate(answerKey):
      count[c == 'T'] += 1
      maxCount = max(maxCount, count[c == 'T'])
      while maxCount + k < r - l + 1:
        count[answerKey[l] == 'T'] -= 1
        l += 1
      ans = max(ans, r - l + 1)

    return ans
