class RangeModule {
  public void addRange(int left, int right) {
    Integer l = ranges.floorKey(left);
    Integer r = ranges.floorKey(right);

    if (l != null && ranges.get(l) >= left)
      left = l;
    if (r != null && ranges.get(r) > right)
      right = ranges.get(r);

    ranges.subMap(left, right).clear();
    ranges.put(left, right);
  }

  public boolean queryRange(int left, int right) {
    Integer l = ranges.floorKey(left);
    return l == null ? false : ranges.get(l) >= right;
  }

  public void removeRange(int left, int right) {
    Integer l = ranges.floorKey(left);
    Integer r = ranges.floorKey(right);

    if (r != null && ranges.get(r) > right)
      ranges.put(right, ranges.get(r));
    if (l != null && ranges.get(l) > left)
      ranges.put(l, left);

    ranges.subMap(left, right).clear();
  }

  private TreeMap<Integer, Integer> ranges = new TreeMap<>();
}
