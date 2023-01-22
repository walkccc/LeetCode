class Solution:
  def numberOfRounds(self, startTime: str, finishTime: str) -> int:
    def getMinutes(s: str) -> int:
      return 60 * int(s[:2]) + int(s[3:])

    start = getMinutes(startTime)
    finish = getMinutes(finishTime)
    if start > finish:
      finish += 60 * 24

    return max(0, finish // 15 - (start + 14) // 15)
