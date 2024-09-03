class SummaryRanges {
  public void addNum(int val) {
    if (intervals.containsKey(val))
      return;

    // the maximum key in `intervals` < `key`
    final Integer lo = intervals.lowerKey(val);
    // the minimum key in `intervals` > `key`
    final Integer hi = intervals.higherKey(val);

    // {lo, intervals.get(lo)[1]} + val + {hi, intervals.get(hi)[1]} = {lo, intervals.get(hi)[1]}
    if (lo != null && hi != null && intervals.get(lo)[1] + 1 == val && val + 1 == hi) {
      intervals.get(lo)[1] = intervals.get(hi)[1];
      intervals.remove(hi);
      // {lo, intervals.get(lo)[1]} + val = {lo, val}
      // Prevent adding duplicate entry by using '>=' instead of '=='.
    } else if (lo != null && intervals.get(lo)[1] + 1 >= val) {
      intervals.get(lo)[1] = Math.max(intervals.get(lo)[1], val);
      // val + {hi, intervals.get(hi)[1]} = {val, intervals.get(hi)[1]}
    } else if (hi != null && val + 1 == hi) {
      intervals.put(val, new int[] {val, intervals.get(hi)[1]});
      intervals.remove(hi);
    } else {
      intervals.put(val, new int[] {val, val});
    }
  }

  public int[][] getIntervals() {
    return intervals.values().stream().toArray(int[][] ::new);
  }

  // {start: (start, end)}
  private TreeMap<Integer, int[]> intervals = new TreeMap<>();
}
