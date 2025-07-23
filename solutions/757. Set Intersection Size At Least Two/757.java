class Solution {
  public int intersectionSizeTwo(int[][] intervals) {
    int ans = 0;
    int mx = -1;
    int secondMax = -1;

    Arrays.sort(intervals, Comparator.comparingInt((int[] interval) -> interval[1])
                               .thenComparingInt((int[] interval) -> - interval[0]));

    for (int[] interval : intervals) {
      final int start = interval[0];
      final int end = interval[1];
      // The maximum and the second maximum still satisfy.
      if (mx >= start && secondMax >= start)
        continue;
      if (mx >= start) {
        // The maximum still satisfy.
        secondMax = mx;
        mx = end; // Add `end` to the set.
        ans += 1;
      } else {
        // The maximum and the second maximum can't satisfy.
        mx = end;            // Add `end` to the set.
        secondMax = end - 1; // Add `end - 1` to the set.
        ans += 2;
      }
    }

    return ans;
  }
}
