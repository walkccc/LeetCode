class Solution {
  public int[] findRightInterval(int[][] intervals) {
    final int n = intervals.length;

    int[] ans = new int[n];
    TreeMap<Integer, Integer> startToIndex = new TreeMap<>();

    for (int i = 0; i < n; ++i)
      startToIndex.put(intervals[i][0], i);

    for (int i = 0; i < n; ++i) {
      Map.Entry<Integer, Integer> entry = startToIndex.ceilingEntry(intervals[i][1]);
      ans[i] = entry == null ? -1 : entry.getValue();
    }

    return ans;
  }
}
