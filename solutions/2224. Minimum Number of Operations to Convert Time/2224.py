class Solution:
  def convertTime(self, current: str, correct: str) -> int:
    ops = [60, 15, 5, 1]

    def getMinutes(s: str) -> int:
      return int(s[:2]) * 60 + int(s[3:])

    diff = getMinutes(correct) - getMinutes(current)
    ans = 0

    for op in ops:
      ans += diff // op
      diff %= op

    return ans
