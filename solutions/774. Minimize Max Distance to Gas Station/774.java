class Solution {
  public double minmaxGasDist(int[] stations, int k) {
    final double kErr = 1e-6;
    double l = 0;
    double r = stations[stations.length - 1] - stations[0];

    while (r - l > kErr) {
      final double m = (l + r) / 2;
      if (check(stations, k, m))
        r = m;
      else
        l = m;
    }

    return l;
  }

  // Returns true if can use <= k gas stations to ensure that each adjacent
  // distance between gas stations <= m.
  private boolean check(int[] stations, int k, double m) {
    for (int i = 1; i < stations.length; ++i) {
      final int diff = stations[i] - stations[i - 1];
      if (diff > m) {
        k -= Math.ceil(diff / m) - 1;
        if (k < 0)
          return false;
      }
    }
    return true;
  };
}
