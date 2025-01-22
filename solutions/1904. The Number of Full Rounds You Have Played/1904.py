class Solution:
  def numberOfRounds(self, loginTime: str, logoutTime: str) -> int:
    start = self._getMinutes(loginTime)
    finish = self._getMinutes(logoutTime)
    if start > finish:
      finish += 60 * 24

    return max(0, finish // 15 - (start + 14) // 15)

  def _getMinutes(self, time: str) -> int:
    h, m = map(int, time.split(':'))
    return 60 * h + m
