class Solution {
  public int daysBetweenDates(String date1, String date2) {
    return Math.abs(daysFrom1971(date1) - daysFrom1971(date2));
  }

  private static final int[] days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  private int daysFrom1971(final String date) {
    final int year = Integer.valueOf(date.substring(0, 4));
    final int month = Integer.valueOf(date.substring(5, 7));
    final int day = Integer.valueOf(date.substring(8));
    int res = 0;
    for (int i = 1971; i < year; ++i)
      res += isLeapYear(i) ? 366 : 365;
    for (int i = 0; i < month; ++i)
      res += days[i];
    if (month > 2 && isLeapYear(year))
      ++res;
    return res + day;
  }

  private boolean isLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  };
}
