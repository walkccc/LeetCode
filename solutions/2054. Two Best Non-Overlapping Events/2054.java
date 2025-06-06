class Solution {
  public int maxTwoEvents(int[][] events) {
    record Event(int time, int value, int isStart) {}
    int ans = 0;
    int maxValue = 0;
    Event[] evts = new Event[events.length * 2];

    for (int i = 0; i < events.length; ++i) {
      final int start = events[i][0];
      final int end = events[i][1];
      final int value = events[i][2];
      evts[i * 2] = new Event(start, value, 1);
      evts[i * 2 + 1] = new Event(end + 1, value, 0);
    }

    Arrays.sort(evts, Comparator.comparingInt(Event::time).thenComparingInt(Event::isStart));

    for (Event evt : evts)
      if (evt.isStart == 1)
        ans = Math.max(ans, evt.value + maxValue);
      else
        maxValue = Math.max(maxValue, evt.value);

    return ans;
  }
}
