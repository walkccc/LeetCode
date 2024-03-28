class Solution:
  def dayOfYear(self, date: str) -> int:
    def isLeapYear(year: int) -> bool:
      return (year % 4 == 0 and year % 100 != 0) or year % 400 == 0

    year = int(date[:4])
    month = int(date[5:7])
    day = int(date[8:])
    days = [31, 29 if isLeapYear(
        year) else 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    return sum(days[:month - 1]) + day
