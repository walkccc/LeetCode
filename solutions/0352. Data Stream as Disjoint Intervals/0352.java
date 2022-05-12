class SummaryRanges {
  public void addNum(int val) {
    if (map.containsKey(val))
      return;

    final Integer lo = map.lowerKey(val);  // maximum in map < key
    final Integer hi = map.higherKey(val); // minimum in map > key

    // {lo, map.get(lo)[1]} + val + {hi, map.get(hi)[1]} = {lo, map.get(hi)[1]}
    if (lo != null && hi != null && map.get(lo)[1] + 1 == val && val + 1 == hi) {
      map.get(lo)[1] = map.get(hi)[1];
      map.remove(hi);
      // {lo, map.get(lo)[1]} + val = {lo, val}
      // (prevent adding duplicate entry by using '>=' instead of '==')
    } else if (lo != null && map.get(lo)[1] + 1 >= val) {
      map.get(lo)[1] = Math.max(map.get(lo)[1], val);
      // val + {hi, map.get(hi)[1]} = {val, map.get(hi)[1]}
    } else if (hi != null && val + 1 == hi) {
      map.put(val, new int[] {val, map.get(hi)[1]});
      map.remove(hi);
    } else {
      map.put(val, new int[] {val, val});
    }
  }

  public int[][] getIntervals() {
    List<int[]> intervals = new ArrayList<>(map.values());
    return intervals.toArray(new int[intervals.size()][]);
  }

  // {start: {start, end}}
  private TreeMap<Integer, int[]> map = new TreeMap<>();
}
