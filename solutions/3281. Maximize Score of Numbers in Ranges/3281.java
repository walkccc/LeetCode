class Solution {
  public int maxPossibleScore(int[] start, int d) {
    Arrays.sort(start);

    long l = 0;
    long r = (start[start.length - 1] + d) - start[0] + 1;

    while (l < r) {
      final long m = (l + r) / 2;
      if (isPossible(start, d, m))
        l = m + 1;
      else
        r = m;
    }

    return (int) (l - 1);
  }

  private boolean isPossible(int[] start, int d, long m) {
    long lastPick = start[0];
    for (int i = 1; i < start.length; ++i) {
      if (lastPick + m > start[i] + d)
        return false;
      lastPick = Math.max(lastPick + m, (long) start[i]);
    }
    return true;
  }
}
