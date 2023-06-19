class Solution {
  public int findPoisonedDuration(int[] timeSeries, int duration) {
    if (duration == 0)
      return 0;

    int ans = 0;

    for (int i = 0; i + 1 < timeSeries.length; ++i)
      ans += Math.min(timeSeries[i + 1] - timeSeries[i], duration);

    return ans + duration;
  }
}
