class Solution {
  public int removeCoveredIntervals(int[][] intervals) {
    Arrays.sort(intervals, Comparator.comparingInt((int[] interval) -> interval[0])
                               .thenComparingInt((int[] interval) -> - interval[1]));

    int ans = 0;
    int prevEnd = 0;

    for (int[] interval : intervals)
      // The current interval is not covered by the previous one.
      if (prevEnd < interval[1]) {
        prevEnd = interval[1];
        ++ans;
      }

    return ans;
  }
}
