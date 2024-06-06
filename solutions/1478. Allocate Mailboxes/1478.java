class Solution {
  public int minDistance(int[] houses, int k) {
    final int n = houses.length;
    int[][] mem = new int[n][k + 1];
    // cost[i][j] := the minimum cost to allocate mailboxes between houses[i]
    // and houses[j]
    int[][] cost = new int[n][n];

    Arrays.stream(mem).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    Arrays.sort(houses);

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        int median = houses[(i + j) / 2];
        for (int x = i; x <= j; ++x)
          cost[i][j] += Math.abs(houses[x] - median);
      }

    return minDistance(houses, 0, k, cost, mem);
  }

  private static final int kMax = 1_000_000;

  // Returns the minimum distance to allocate k mailboxes for houses[i..n).
  private int minDistance(int[] houses, int i, int k, int[][] cost, int[][] mem) {
    if (i == houses.length && k == 0)
      return 0;
    if (i == houses.length || k == 0)
      return kMax;
    if (mem[i][k] != Integer.MAX_VALUE)
      return mem[i][k];

    for (int j = i; j < houses.length; ++j)
      mem[i][k] = Math.min(mem[i][k], cost[i][j] + minDistance(houses, j + 1, k - 1, cost, mem));

    return mem[i][k];
  }
}
