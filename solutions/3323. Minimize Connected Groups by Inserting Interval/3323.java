class Solution {
  public int minConnectedGroups(int[][] intervals, int k) {
    int mergedIntervals = 0;
    int maxMergedIntervals = 0;

    intervals = merge(intervals);

    int i = 0;
    for (int[] interval : intervals) {
      final int end = interval[1];
      while (i < intervals.length && end + k >= intervals[i][0]) {
        ++mergedIntervals;
        ++i;
      }
      --mergedIntervals; // Exclude intervals[i].
      maxMergedIntervals = Math.max(maxMergedIntervals, mergedIntervals);
    }

    return intervals.length - maxMergedIntervals;
  }

  // Same as 56. Merge Intervals
  public int[][] merge(int[][] intervals) {
    List<int[]> res = new ArrayList<>();
    Arrays.sort(intervals, Comparator.comparingInt((int[] interval) -> interval[0]));
    for (int[] interval : intervals)
      if (res.isEmpty() || res.get(res.size() - 1)[1] < interval[0])
        res.add(interval);
      else
        res.get(res.size() - 1)[1] = Math.max(res.get(res.size() - 1)[1], interval[1]);
    return res.toArray(int[][] ::new);
  }
}
