class Solution:
  def daysBetweenDates(self, date1: str, date2: str) -> int:
    days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    def isLeapYear(year: int) -> bool:
      return year % 4 == 0 and year % 100 != 0 or year % 400 == 0

    def daysFrom1971(date: str) -> int:
      year, month, day = map(int, date.split('-'))
      return (365 * (year - 1971) + sum(map(isLeapYear, range(1971, year))) +
              sum(days[:month]) + day + (month > 2 and isLeapYear(year)))

    return abs(daysFrom1971(date1) - daysFrom1971(date2))
