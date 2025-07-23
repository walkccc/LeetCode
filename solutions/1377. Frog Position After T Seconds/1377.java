class Solution {
  public double frogPosition(int n, int[][] edges, int t, int target) {
    List<Integer>[] tree = new List[n + 1];
    Queue<Integer> q = new ArrayDeque<>(List.of(1));
    boolean[] seen = new boolean[n + 1];
    double[] prob = new double[n + 1];

    seen[1] = true;
    prob[1] = 1.0;

    for (int i = 1; i <= n; ++i)
      tree[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    while (!q.isEmpty() && t-- > 0)
      for (int sz = q.size(); sz > 0; --sz) {
        final int a = q.poll();
        int nChildren = 0;
        for (final int b : tree[a])
          if (!seen[b])
            ++nChildren;
        for (final int b : tree[a]) {
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
