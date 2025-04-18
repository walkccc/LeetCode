class Solution {
  public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
    final int n = startTime.length;
    final int[] gaps = getGaps(eventTime, startTime, endTime);
    int ans = 0;
    int[] maxLeft = new int[n + 1];  // maxLeft[i] := max(gaps[0..i])
    int[] maxRight = new int[n + 1]; // maxRight[i] := max(gaps[i..n])

    maxLeft[0] = gaps[0];
    maxRight[n] = gaps[n];

    for (int i = 1; i < n + 1; ++i)
      maxLeft[i] = Math.max(gaps[i], maxLeft[i - 1]);

    for (int i = n - 1; i >= 0; --i)
      maxRight[i] = Math.max(gaps[i], maxRight[i + 1]);

    for (int i = 0; i < n; ++i) {
      final int currMeetingTime = endTime[i] - startTime[i];
      final int adjacentGapsSum = gaps[i] + gaps[i + 1];
      final boolean canMoveMeeting =
          currMeetingTime <= Math.max(i > 0 ? maxLeft[i - 1] : 0, //
                                      i + 2 < n + 1 ? maxRight[i + 2] : 0);
      ans = Math.max(ans, adjacentGapsSum + (canMoveMeeting ? currMeetingTime : 0));
    }

    return ans;
  }

  private int[] getGaps(int eventTime, int[] startTime, int[] endTime) {
    int[] gaps = new int[startTime.length + 1];
    gaps[0] = startTime[0];
    for (int i = 1; i < startTime.length; ++i)
      gaps[i] = startTime[i] - endTime[i - 1];
    gaps[startTime.length] = eventTime - endTime[endTime.length - 1];
    return gaps;
  }
}
