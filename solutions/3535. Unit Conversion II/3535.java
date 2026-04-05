class Solution {
  public int[] queryConversions(int[][] conversions, int[][] queries) {
    int[] units = baseUnitConversions(conversions);
    int[] ans = new int[queries.length];

    for (int i = 0; i < queries.length; ++i) {
      final int u = queries[i][0];
      final int v = queries[i][1];
      // By Fermat's little theorem.
      ans[i] = (int) ((long) units[v] * modPow(units[u], MOD - 2) % MOD);
    }

    return ans;
  }

  private static final int MOD = 1_000_000_007;

  private int[] baseUnitConversions(int[][] conversions) {
    final int n = conversions.length + 1;
    int[] ans = new int[n];
    ans[0] = 1;
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(0));
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] conversion : conversions) {
      final int u = conversion[0];
      final int v = conversion[1];
      final int factor = conversion[2];
      graph[u].add(new Pair<>(v, factor));
    }

    while (!q.isEmpty()) {
      final int u = q.poll();
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int factor = pair.getValue();
        ans[v] = (int) ((long) ans[u] * factor % MOD);
        q.offer(v);
      }
    }

    return ans;
  }

  private int modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return (int) (x * modPow(x % MOD, (n - 1)) % MOD);
    return modPow(x * x % MOD, (n / 2)) % MOD;
  }
}
