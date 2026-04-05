class Solution {
  public int assignEdgeWeights(int[][] edges) {
    final int n = edges.size() + 1;
    List<Integer>[] graph = new List[n + 1];
    Arrays.setAll(graph, i -> new ArrayList<>());

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    Queue<Integer> q = new ArrayDeque<>(List.of(1));
    boolean[] seen = new boolean[n + 1];
    seen[1] = true;

    int step = 0;
    for (step = 0; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int u = q.poll();
        for (final int v : graph[u])
          if (!seen[v]) {
            q.offer(v);
            seen[v] = true;
          }
      }

    return step > 0 ? modPow(2, step - 2) : 0;
  }

  private static final int MOD = 1_000_000_007;

  private int modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return (int) (x * modPow(x % MOD, (n - 1)) % MOD);
    return modPow(x * x % MOD, (n / 2)) % MOD;
  }
}
