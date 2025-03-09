class Solution {
  public int numberOfBoomerangs(int[][] points) {
    int ans = 0;

    for (int[] p : points) {
      Map<Integer, Integer> distCount = new HashMap<>();
      for (int[] q : points) {
        final int dist = (int) getDist(p, q);
        distCount.merge(dist, 1, Integer::sum);
      }
      for (final int freq : distCount.values())
        ans += freq * (freq - 1); // C(freq, 2)
    }

    return ans;
  }

  private double getDist(int[] p, int[] q) {
    return Math.pow(p[0] - q[0], 2) + Math.pow(p[1] - q[1], 2);
  }
}
