class Solution {
  public double frogPosition(int n, int[][] edges, int t, int target) {
    List<Integer>[] graph = new List[n + 1];
    double[] prob = new double[n + 1];
    boolean[] seen = new boolean[n + 1];
    Queue<Integer> q = new LinkedList<>(Arrays.asList(1));

    prob[1] = 1.0;
    seen[1] = true;

    for (int i = 1; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    while (!q.isEmpty() && t-- > 0)
      for (int size = q.size(); size > 0; --size) {
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
