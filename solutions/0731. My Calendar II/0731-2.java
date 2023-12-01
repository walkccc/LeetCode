class MyCalendarTwo {
  public boolean book(int start, int end) {
    timeline.merge(start, 1, Integer::sum);
    timeline.merge(end, -1, Integer::sum);

    int activeEvents = 0;

    for (final int count : timeline.values()) {
      activeEvents += count;
      if (activeEvents > 2) {
        if (timeline.merge(start, -1, Integer::sum) == 0)
          timeline.remove(start);
        if (timeline.merge(end, 1, Integer::sum) == 0)
          timeline.remove(end);
        return false;
      }
    }

    return true;
  }

  private Map<Integer, Integer> timeline = new TreeMap<>();
}
