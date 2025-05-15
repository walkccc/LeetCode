class MyCalendar {
  public boolean book(int startTime, int endTime) {
    for (int[] t : line)
      if (Math.max(t[0], startTime) < Math.min(t[1], endTime))
        return false;
    line.add(new int[] {start, end});
    return true;
  }

  private List<int[]> line = new ArrayList<>();
}
