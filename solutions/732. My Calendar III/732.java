class MyCalendarThree {
  public int book(int start, int end) {
    timeline.merge(start, 1, Integer::sum);
    timeline.merge(end, -1, Integer::sum);

    int ans = 0;
    int activeEvents = 0;

    for (final int count : timeline.values()) {
      activeEvents += count;
      ans = Math.max(ans, activeEvents);
    }

    return ans;
  }

  private Map<Integer, Integer> timeline = new TreeMap<>();
}
