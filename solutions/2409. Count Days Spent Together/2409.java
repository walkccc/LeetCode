class Solution {
  public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob,
                               String leaveBob) {
    final int arriveA = toDays(arriveAlice);
    final int leaveA = toDays(leaveAlice);
    final int arriveB = toDays(arriveBob);
    final int leaveB = toDays(leaveBob);
    int ans = 0;

    for (int day = 1; day <= 365; ++day)
      if (arriveA <= day && day <= leaveA && arriveB <= day && day <= leaveB)
        ++ans;

    return ans;
  }

  private final int[] days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  private int toDays(final String s) {
    final int month = (s.charAt(0) - '0') * 10 + (s.charAt(1) - '0');
    final int day = (s.charAt(3) - '0') * 10 + (s.charAt(4) - '0');
    int prevDays = 0;
    for (int m = 1; m < month; ++m)
      prevDays += days[m];
    return prevDays + day;
  }
}
