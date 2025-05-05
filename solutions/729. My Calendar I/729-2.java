class MyCalendar {
  public boolean book(int start, int end) {
    Integer low = line.lowerKey(end);

    if (low == null || line.get(low) <= start) {
      line.put(start, end);
      return true;
    }

    return false;
  }

  private TreeMap<Integer, Integer> line = new TreeMap<>();
}
