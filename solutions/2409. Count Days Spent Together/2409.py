class Solution:
  def countDaysTogether(
      self,
      arriveAlice: str,
      leaveAlice: str,
      arriveBob: str,
      leaveBob: str,
  ) -> int:
    days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    def toDays(s: str) -> int:
      month = int(s[:2])
      day = int(s[3:])
      prevDays = 0
      for m in range(1, month):
        prevDays += days[m]
      return prevDays + day

    arriveA = toDays(arriveAlice)
    leaveA = toDays(leaveAlice)
    arriveB = toDays(arriveBob)
    leaveB = toDays(leaveBob)
    ans = 0

    for day in range(1, 366):
      if arriveA <= day and day <= leaveA and arriveB <= day and day <= leaveB:
        ans += 1

    return ans
