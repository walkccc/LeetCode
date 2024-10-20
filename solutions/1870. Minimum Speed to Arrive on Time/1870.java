class Solution {
  public int minSpeedOnTime(int[] dist, double hour) {
    int ans = -1;
    int l = 1;
    int r = (int) 1e7;

    while (l <= r) {
      final int m = (l + r) / 2;
      if (time(dist, hour, m) > hour) {
        l = m + 1;
      } else {
        ans = m;
        r = m - 1;
      }
    }

    return ans;
  }

  private double time(int[] dist, double hour, int speed) {
    double sum = 0;
    for (int i = 0; i < dist.length - 1; ++i)
      sum += Math.ceil((double) dist[i] / speed);
    return sum + (double) dist[dist.length - 1] / speed;
  }
}
