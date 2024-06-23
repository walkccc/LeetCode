class Solution {
  // Similar to 2203. Minimum Weighted Subgraph With the Required Paths
  public boolean[] findAnswer(int n, int[][] edges) {
    boolean[] ans = new boolean[edges.length];
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int w = edge[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    int[] from0 = dijkstra(graph, 0);
    int[] from1 = dijkstra(graph, n - 1);

    for (int i = 0; i < edges.length; ++i) {
      final int u = edges[i][0];
      final int v = edges[i][1];
      final int w = edges[i][2];
      ans[i] = from0[u] + w + from1[v] == from0[n - 1] || //
               from0[v] + w + from1[u] == from0[n - 1];
    }

    return ans;
  }

  private static int kMax = 1_000_000_000;

  private int[] dijkstra(List<Pair<Integer, Integer>>[] graph, int src) {
    int[] dist = new int[graph.length];
    Arrays.fill(dist, kMax);
    // (d, u)
    Queue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));

    dist[src] = 0;
    minHeap.offer(new Pair<>(dist[src], src));

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek().getKey();
      final int u = minHeap.poll().getValue();
      if (d > dist[u])
        continue;
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.offer(new Pair<>(dist[v], v));
        }
      }
    }

    return dist;
  }
};
