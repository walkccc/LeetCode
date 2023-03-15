class Solution {
  public int numberOfRounds(String startTime, String finishTime) {
    final int start = getMinutes(startTime);
    int finish = getMinutes(finishTime);
    if (start > finish)
      finish += 60 * 24;
    return Math.max(0, finish / 15 - (start + 14) / 15);
  }

  private int getMinutes(final String s) {
    return 60 * Integer.valueOf(s.substring(0, 2)) + Integer.valueOf(s.substring(3));
  }
}
