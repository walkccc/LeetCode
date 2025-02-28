class Solution {
  public int[] assignBikes(int[][] workers, int[][] bikes) {
    final int n = workers.length;
    final int m = bikes.length;
    int[] ans = new int[n];
    boolean[] usedBikes = new boolean[m];
    // buckets[k] := (i, j), where k = dist(workers[i], bikes[j])
    List<Pair<Integer, Integer>>[] buckets = new List[2001];

    for (int i = 0; i < 2001; ++i)
      buckets[i] = new ArrayList<>();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        buckets[dist(workers[i], bikes[j])].add(new Pair<>(i, j));

    Arrays.fill(ans, -1);

    for (int k = 0; k < 2001; ++k)
      for (Pair<Integer, Integer> pair : buckets[k]) {
        final int i = pair.getKey();
        final int j = pair.getValue();
        if (ans[i] == -1 && !usedBikes[j]) {
          ans[i] = j;
          usedBikes[j] = true;
        }
      }

    return ans;
  }

  private int dist(int[] p1, int[] p2) {
    return Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
  }
}
