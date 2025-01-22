class Solution {
  public long minNumberOfSeconds(int mountainHeight, int[] workerTimes) {
    long l = 1;
    long r = (long) Arrays.stream(workerTimes).min().getAsInt() * mountainHeight *
             (mountainHeight + 1) / 2;

    while (l < r) {
      final long m = (l + r) / 2;
      if (getReducedHeight(workerTimes, m) < mountainHeight)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }

  // Returns the total height reduced by all workers in `m` seconds.
  private int getReducedHeight(int[] workerTimes, long m) {
    int reducedHeight = 0;
    for (int workerTime : workerTimes)
      // The height `x` that a worker with working time `w` reduces in `m`
      // seconds.
      // w * (1 + 2 + ... + x) <= m
      //       (1 + x) * x / 2 <= m / w
      //   x^2 + x - 2 * m / w <= 0
      //                     x <= (-1 + sqrt(1 + 8 * m / w)) / 2
      reducedHeight += (int) ((-1 + Math.sqrt(1 + 8 * m / workerTime)) / 2);
    return reducedHeight;
  }
}
