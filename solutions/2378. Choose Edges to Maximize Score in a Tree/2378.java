class Solution {
  public long maxScore(int[][] edges) {
    final int n = edges.length;
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int i = 0; i < n; ++i) {
      final int parent = edges[i][0];
      final int weight = edges[i][1];
      if (parent != -1)
        graph[parent].add(new Pair<>(i, weight));
    }

    Pair<Long, Long> pair = dfs(graph, 0);
    final long takeRoot = pair.getKey();
    final long notTakeRoot = pair.getValue();
    return Math.max(takeRoot, notTakeRoot);
  }

  // return (max sum at u if we take one u->v edge,
  //         max sum at u if we don't take any child edge)
  private Pair<Long, Long> dfs(List<Pair<Integer, Integer>>[] graph, int u) {
    long bestEdge = 0;
    long notTakeU = 0;

    for (Pair<Integer, Integer> node : graph[u]) {
      final int v = node.getKey();
      final int w = node.getValue();
      Pair<Long, Long> pair = dfs(graph, v);
      final long takeV = pair.getKey();
      final long notTakeV = pair.getValue();
      bestEdge = Math.max(bestEdge, w + notTakeV - takeV);
      notTakeU += takeV;
    }

    return new Pair<>(bestEdge + notTakeU, notTakeU);
  }
}
