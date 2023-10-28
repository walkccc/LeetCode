class Solution {
  public int findMinDifference(List<String> timePoints) {
    int ans = 24 * 60;
    int first = 24 * 60;
    boolean[] bucket = new boolean[24 * 60];

    for (final String timePoint : timePoints) {
      final int num =
          Integer.valueOf(timePoint.substring(0, 2)) * 60 + Integer.valueOf(timePoint.substring(3));
      first = Math.min(first, num);
      if (bucket[num])
        return 0;
      bucket[num] = true;
    }

    int prev = first;

    for (int i = first + 1; i < bucket.length; ++i)
      if (bucket[i]) {
        ans = Math.min(ans, i - prev);
        prev = i;
      }

    return Math.min(ans, 24 * 60 - prev + first);
  }
}
