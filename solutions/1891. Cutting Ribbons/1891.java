class Solution {
  public int maxLength(int[] ribbons, int k) {
    int l = 1;
    int r = (int) (Arrays.stream(ribbons).asLongStream().sum() / k) + 1;

    while (l < r) {
      final int m = (l + r) / 2;
      if (!isCutPossible(ribbons, m, k))
        r = m;
      else
        l = m + 1;
    }

    return l - 1;
  }

  private boolean isCutPossible(int[] ribbons, int length, int k) {
    int count = 0;
    for (final int ribbon : ribbons)
      count += ribbon / length;
    return count >= k;
  }
}
