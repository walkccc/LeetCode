class Graph {
  public Graph(int n, int[][] edges) {
    graph = new List[n];
    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();
    for (int[] edge : edges)
      addEdge(edge);
  }

  public void addEdge(int[] edge) {
    final int u = edge[0];
    final int v = edge[1];
    final int w = edge[2];
    graph[u].add(new Pair<>(v, w));
  }

  public int shortestPath(int node1, int node2) {
    int[] dist = new int[graph.length];
    Arrays.fill(dist, Integer.MAX_VALUE);
    // (d, u)
    Queue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));

    dist[node1] = 0;
    minHeap.offer(new Pair<>(dist[node1], node1));

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek().getKey();
      final int u = minHeap.poll().getValue();
      if (u == node2)
        return d;
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.offer(new Pair<>(dist[v], v));
        }
      }
    }

    return -1;
  }

  private List<Pair<Integer, Integer>>[] graph;
}
