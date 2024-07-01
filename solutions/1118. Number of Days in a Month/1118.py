class Solution:
  def numberOfDays(self, year: int, month: int) -> int:
    days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    def isLeapYear(year: int) -> bool:
      return year % 4 == 0 and year % 100 != 0 or year % 400 == 0
    return 29 if month == 2 and isLeapYear(year) else days[month]
