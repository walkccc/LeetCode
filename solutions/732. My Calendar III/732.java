class MyCalendarThree {
  public int book(int start, int end) {
    line.merge(start, 1, Integer::sum);
    line.merge(end, -1, Integer::sum);

    int ans = 0;
    int activeEvents = 0;

    for (final int count : line.values()) {
      activeEvents += count;
      ans = Math.max(ans, activeEvents);
    }

    return ans;
  }

  private Map<Integer, Integer> line = new TreeMap<>();
}
