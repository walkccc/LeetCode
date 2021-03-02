class MyCalendar {
  public boolean book(int start, int end) {
    final Integer prev = calendar.floorKey(start); // greatest element < start
    final Integer next = calendar.ceilingKey(start); // 1st element >= start

    if ((prev == null || calendar.get(prev) <= start) &&
        (next == null || end <= next)) {
      calendar.put(start, end);
      return true;
    }

    return false;
  }

  private TreeMap<Integer, Integer> calendar = new TreeMap<>();
}
