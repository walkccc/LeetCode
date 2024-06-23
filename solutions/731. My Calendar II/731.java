class MyCalendarTwo {
  public boolean book(int start, int end) {
    for (int[] overlap : overlaps)
      if (Math.max(start, overlap[0]) < Math.min(end, overlap[1]))
        return false;

    for (int[] range : ranges) {
      final int maxStart = Math.max(start, range[0]);
      final int minEnd = Math.min(end, range[1]);
      if (maxStart < minEnd)
        overlaps.add(new int[] {maxStart, minEnd});
    }

    ranges.add(new int[] {start, end});
    return true;
  }

  List<int[]> ranges = new ArrayList<>();
  List<int[]> overlaps = new ArrayList<>();
}
