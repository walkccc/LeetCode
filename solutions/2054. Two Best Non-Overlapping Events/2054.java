class Event {
  public int time;
  public int value;
  public int isStart;
  public Event(int time, int value, int isStart) {
    this.time = time;
    this.value = value;
    this.isStart = isStart;
  }
}

class Solution {
  public int maxTwoEvents(int[][] events) {
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

    Arrays.sort(evts,
                (a, b)
                    -> a.time == b.time ? Integer.compare(a.isStart, b.isStart)
                                        : Integer.compare(a.time, b.time));

    for (Event evt : evts)
      if (evt.isStart == 1)
        ans = Math.max(ans, evt.value + maxValue);
      else
        maxValue = Math.max(maxValue, evt.value);

    return ans;
  }
}
