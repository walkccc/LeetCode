class Solution {
  public int removeCoveredIntervals(int[][] intervals) {
    // If the two intervals have the same `start`, put the one with a larger
    // `end` first.
    Arrays.sort(intervals,
                (a, b) -> a[0] == b[0] ? Integer.compare(b[1], a[1]) : Integer.compare(a[0], b[0]));

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
