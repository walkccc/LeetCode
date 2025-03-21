class CountIntervals {
  public void add(int left, int right) {
    while (isOverlapped(left, right)) {
      final int l = intervals.floorKey(right);
      final int r = intervals.get(l);
      left = Math.min(left, l);
      right = Math.max(right, r);
      intervals.remove(l);
      count -= r - l + 1;
    }

    intervals.put(left, right);
    count += right - left + 1;
  }

  public int count() {
    return count;
  }

  private TreeMap<Integer, Integer> intervals = new TreeMap<>();
  private int count = 0;

  private boolean isOverlapped(int left, int right) {
    // L := the maximum number <= end
    Integer l = intervals.floorKey(right);
    return l != null && intervals.get(l) >= left;
  }
}
