class MyCalendarThree {
  public int book(int start, int end) {
    timeline.put(start, timeline.getOrDefault(start, 0) + 1);
    timeline.put(end, timeline.getOrDefault(end, 0) - 1);

    int ans = 0;
    int k = 0;

    for (final int count : timeline.values())
      ans = Math.max(ans, k += count);

    return ans;
  }

  private Map<Integer, Integer> timeline = new TreeMap<>();
}
