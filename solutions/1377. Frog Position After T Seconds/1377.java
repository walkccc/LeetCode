class Solution {
  public double frogPosition(int n, int[][] edges, int t, int target) {
    List<Integer>[] graph = new List[n + 1];
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(1));
    boolean[] seen = new boolean[n + 1];
    double[] prob = new double[n + 1];

    seen[1] = true;
    prob[1] = 1.0;

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] e : edges) {
      final int u = e[0];
      final int v = e[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    while (!q.isEmpty() && t-- > 0)
      for (int sz = q.size(); sz > 0; --sz) {
        final int a = q.poll();
        int nChildren = 0;
        for (final int b : graph[a])
          if (!seen[b])
            ++nChildren;
        for (final int b : graph[a]) {
          if (seen[b])
            continue;
          seen[b] = true;
          prob[b] = prob[a] / nChildren;
          q.add(b);
        }
        if (nChildren > 0)
          prob[a] = 0.0;
      }

    return prob[target];
  }
}
