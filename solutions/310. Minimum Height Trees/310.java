class Solution {
  public List<Integer> findMinHeightTrees(int n, int[][] edges) {
    if (n == 0 || edges.length == 0)
      return List.of(0);

    List<Integer> ans = new ArrayList<>();
    Map<Integer, Set<Integer>> graph = new HashMap<>();

    for (int i = 0; i < n; ++i)
      graph.put(i, new HashSet<>());

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph.get(u).add(v);
      graph.get(v).add(u);
    }

    for (Map.Entry<Integer, Set<Integer>> entry : graph.entrySet()) {
      final int label = entry.getKey();
      Set<Integer> children = entry.getValue();
      if (children.size() == 1)
        ans.add(label);
    }

    while (n > 2) {
      n -= ans.size();
      List<Integer> nextLeaves = new ArrayList<>();
      for (final int leaf : ans) {
        final int u = (int) graph.get(leaf).iterator().next();
        graph.get(u).remove(leaf);
        if (graph.get(u).size() == 1)
          nextLeaves.add(u);
      }
      ans = nextLeaves;
    }

    return ans;
  }
}
