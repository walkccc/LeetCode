class Solution {
  public int eraseOverlapIntervals(int[][] intervals) {
    int ans = 0;
    int currentEnd = Integer.MIN_VALUE;

    Arrays.sort(intervals, (a, b) -> a[1] - b[1]);

    for (final int[] interval : intervals)
      if (interval[0] >= currentEnd)
        currentEnd = interval[1];
      else
        ++ans;

    return ans;
  }
}