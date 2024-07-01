class MyCalendar {
  public boolean book(int start, int end) {
    Integer low = timeline.lowerKey(end);

    if (low == null || timeline.get(low) <= start) {
      timeline.put(start, end);
      return true;
    }

    return false;
  }

  private TreeMap<Integer, Integer> timeline = new TreeMap<>();
}
