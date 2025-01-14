class Solution {
  public long maximumImportance(int n, int[][] roads) {
    long ans = 0;
    long[] count = new long[n];

    for (int[] road : roads) {
      final int u = road[0];
      final int v = road[1];
      ++count[u];
      ++count[v];
    }

    Arrays.sort(count);

    for (int i = 0; i < n; ++i)
      ans += (i + 1) * count[i];

    return ans;
  }
}
