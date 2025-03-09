class Solution {
  public int visibleMountains(int[][] peaks) {
    int ans = 0;
    int maxRightFoot = 0;

    Arrays.sort(peaks, (a, b) -> {
      final int leftFootA = a[0] - a[1];
      final int leftFootB = b[0] - b[1];
      return leftFootA == leftFootB ? Integer.compare(b[0], a[0])
                                    : Integer.compare(leftFootA, leftFootB);
    });

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
