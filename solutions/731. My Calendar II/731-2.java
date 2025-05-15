class MyCalendarTwo {
  public boolean book(int start, int end) {
    line.merge(start, 1, Integer::sum);
    line.merge(end, -1, Integer::sum);

    int activeEvents = 0;

    for (final int count : line.values()) {
      activeEvents += count;
      if (activeEvents > 2) {
        if (line.merge(start, -1, Integer::sum) == 0)
          line.remove(start);
        if (line.merge(end, 1, Integer::sum) == 0)
          line.remove(end);
        return false;
      }
    }

    return true;
  }

  private Map<Integer, Integer> line = new TreeMap<>();
}
