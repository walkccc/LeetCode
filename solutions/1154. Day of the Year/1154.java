class Solution {
  public int dayOfYear(String date) {
    int ans = 0;
    int year = Integer.valueOf(date.substring(0, 4));
    int month = Integer.valueOf(date.substring(5, 7));
    int day = Integer.valueOf(date.substring(8));
    int[] days = new int[] {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < month - 1; ++i)
      ans += days[i];

    return ans + day;
  }

  private boolean isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  }
}
