class Solution {
  public int[][] modifiedGraphEdges(int n, int[][] edges, int source, int destination, int target) {
    final int kMax = 2_000_000_000;
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int w = edge[2];
      if (w == -1)
        continue;
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    int distToDestination = dijkstra(graph, source, destination);
    if (distToDestination < target)
      return new int[0][];
    if (distToDestination == target) {
      // Change the weights of negative edges to an impossible value.
      for (int[] edge : edges)
        if (edge[2] == -1)
          edge[2] = kMax;
      return edges;
    }

    for (int i = 0; i < edges.length; ++i) {
      final int u = edges[i][0];
      final int v = edges[i][1];
      final int w = edges[i][2];
      if (w != -1)
        continue;
      edges[i][2] = 1;
      graph[u].add(new Pair<>(v, 1));
      graph[v].add(new Pair<>(u, 1));
      distToDestination = dijkstra(graph, source, destination);
      if (distToDestination <= target) {
        edges[i][2] += target - distToDestination;
        // Change the weights of negative edges to an impossible value.
        for (int j = i + 1; j < edges.length; ++j)
          if (edges[j][2] == -1)
            edges[j][2] = kMax;
        return edges;
      }
    }

    return new int[0][];
  }

  private int dijkstra(List<Pair<Integer, Integer>>[] graph, int src, int dst) {
    int[] dist = new int[graph.length];
    Arrays.fill(dist, Integer.MAX_VALUE);
    // (d, u)
    Queue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>((a, b) -> a.getKey() - b.getKey());

    dist[src] = 0;
    minHeap.offer(new Pair<>(dist[src], src));

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek().getKey();
      final int u = minHeap.poll().getValue();
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.offer(new Pair<>(dist[v], v));
        }
      }
    }

    return dist[dst];
  }
}
