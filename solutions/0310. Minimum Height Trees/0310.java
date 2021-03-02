class Solution {
  public List<Integer> findMinHeightTrees(int n, int[][] edges) {
    if (n == 0 || edges.length == 0)
      return new ArrayList<>(Arrays.asList(0));

    List<Integer> ans = new ArrayList<>();
    Map<Integer, Set<Integer>> graph = new HashMap<>();

    for (int i = 0; i < n; ++i)
      graph.put(i, new HashSet<>());

    for (int[] edge : edges) {
      graph.get(edge[0]).add(edge[1]);
      graph.get(edge[1]).add(edge[0]);
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
        final int j = (int) graph.get(leaf).iterator().next();
        graph.get(j).remove(leaf);
        if (graph.get(j).size() == 1)
          nextLeaves.add(j);
      }
      ans = nextLeaves;
    }

    return ans;
  }
}
