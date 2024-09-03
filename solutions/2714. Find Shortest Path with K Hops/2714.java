class Solution {
  // Similar to 787. Cheapest Flights Within K Stops
  public int shortestPathWithHops(int n, int[][] edges, int s, int d, int k) {
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int w = edge[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    return dijkstra(graph, s, d, k);
  }

  private int dijkstra(List<Pair<Integer, Integer>>[] graph, int src, int dst, int k) {
    int[][] dist = new int[graph.length][k + 1];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    // (d, u, hops)
    Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));

    dist[src][k] = 0;
    minHeap.offer(new int[] {dist[src][k], src, k});

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek()[0];
      final int u = minHeap.peek()[1];
      final int hops = minHeap.poll()[2];
      if (u == dst)
        return d;
      if (dist[u][hops] > d)
        continue;
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        // Go from u -> v with w cost.
        if (d + w < dist[v][hops]) {
          dist[v][hops] = d + w;
          minHeap.offer(new int[] {dist[v][hops], v, hops});
        }
        // Hop from u -> v with 0 cost.
        if (hops > 0 && d < dist[v][hops - 1]) {
          dist[v][hops - 1] = d;
          minHeap.offer(new int[] {dist[v][hops - 1], v, hops - 1});
        }
      }
    }

    throw new IllegalArgumentException();
  }
}
