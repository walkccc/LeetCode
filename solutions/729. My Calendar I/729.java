class MyCalendar {
  public boolean book(int start, int end) {
    for (int[] t : timeline)
      if (Math.max(t[0], start) < Math.min(t[1], end))
        return false;
    timeline.add(new int[] {start, end});
    return true;
  }

  private List<int[]> timeline = new ArrayList<>();
}
