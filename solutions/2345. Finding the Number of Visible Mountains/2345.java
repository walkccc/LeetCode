class Solution {
  public int visibleMountains(int[][] peaks) {
    int ans = 0;
    int maxRightFoot = 0;

    Arrays.sort(peaks, Comparator.comparingInt((int[] peak) -> peak[0] - peak[1])
                           .thenComparing((int[] peak) -> peak[0], Comparator.reverseOrder()));

    for (int i = 0; i < peaks.length; ++i) {
      final boolean overlapWithNext = i + 1 < peaks.length && Arrays.equals(peaks[i], peaks[i + 1]);
      final int currRightFoot = peaks[i][0] + peaks[i][1];
      if (currRightFoot > maxRightFoot) {
        if (!overlapWithNext)
          ++ans;
        maxRightFoot = currRightFoot;
      }
    }

    return ans;
  }
}
