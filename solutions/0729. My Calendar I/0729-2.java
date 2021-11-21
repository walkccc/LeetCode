class MyCalendar {
  public boolean book(int start, int end) {
    Integer low = ranges.lowerKey(end);

    if (low == null || ranges.get(low) <= start) {
      ranges.put(start, end);
      return true;
    }

    return false;
  }

  private TreeMap<Integer, Integer> ranges = new TreeMap<>();
}
