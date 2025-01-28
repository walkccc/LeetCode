class Solution {
  public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
    List<Integer> ans = new ArrayList<>();
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] invocation : invocations) {
      final int u = invocation[0];
      final int v = invocation[1];
      graph[u].add(v);
    }

    Queue<Integer> q = new ArrayDeque<>(List.of(k));
    boolean[] seen = new boolean[n];
    seen[k] = true;

    while (!q.isEmpty())
      for (int sz = q.size(); sz > 0; --sz)
        for (final int v : graph[q.poll()])
          if (!seen[v]) {
            q.offer(v);
            seen[v] = true;
          }

    for (int u = 0; u < n; ++u) {
      if (seen[u])
        continue;
      for (final int v : graph[u])
        if (seen[v]) {
          ans = new ArrayList<>(n);
          for (int i = 0; i < n; ++i)
            ans.add(i);
          return ans;
        }
      ans.add(u);
    }

    return ans;
  }
}
