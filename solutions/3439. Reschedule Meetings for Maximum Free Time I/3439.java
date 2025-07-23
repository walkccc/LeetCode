class Solution {
  public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
    int[] gaps = getGaps(eventTime, startTime, endTime);
    int windowSum = Arrays.stream(gaps, 0, k + 1).sum();
    int ans = windowSum;

    for (int i = k + 1; i < gaps.length; i++) {
      windowSum += gaps[i] - gaps[i - k - 1];
      ans = Math.max(ans, windowSum);
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
