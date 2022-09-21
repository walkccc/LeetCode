class Solution {
  public List<List<Integer>> getAncestors(int n, int[][] edges) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer>[] graph = new List[n];
    TreeSet<Integer>[] A = new TreeSet[n]; // {u: {ancestors}}
    int[] inDegree = new int[n];

    for (int i = 0; i < n; ++i) {
      graph[i] = new ArrayList<>();
      A[i] = new TreeSet<>();
    }

    // build graph
    for (int[] e : edges) {
      final int u = e[0];
      final int v = e[1];
      graph[u].add(v);
      ++inDegree[v];
    }

    // topology
    Queue<Integer> q = IntStream.range(0, n)
                           .filter(i -> inDegree[i] == 0)
                           .boxed()
                           .collect(Collectors.toCollection(ArrayDeque::new));

    while (!q.isEmpty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int u = q.poll();
        for (final int v : graph[u]) {
          A[v].add(u);
          A[v].addAll(A[u]);
          if (--inDegree[v] == 0)
            q.offer(v);
        }
      }
    }

    for (TreeSet<Integer> ancestors : A)
      ans.add(new ArrayList<>(ancestors));

    return ans;
  }
}
