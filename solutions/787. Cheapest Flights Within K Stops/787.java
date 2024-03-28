class Solution {
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] flight : flights) {
      final int u = flight[0];
      final int v = flight[1];
      final int w = flight[2];
      graph[u].add(new Pair<>(v, w));
    }

    return dijkstra(graph, src, dst, k);
  }

  private int dijkstra(List<Pair<Integer, Integer>>[] graph, int src, int dst, int k) {
    int[][] dist = new int[graph.length][k + 2];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    // (d, u, stops)
    Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);

    dist[src][k + 1] = 0;
    minHeap.offer(new int[] {dist[src][k + 1], src, k + 1});

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek()[0];
      final int u = minHeap.peek()[1];
      final int stops = minHeap.poll()[2];
      if (u == dst)
        return d;
      if (stops == 0)
        continue;
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        if (d + w < dist[v][stops - 1]) {
          dist[v][stops - 1] = d + w;
          minHeap.offer(new int[] {dist[v][stops - 1], v, stops - 1});
        }
      }
    }

    return -1;
  }
}
