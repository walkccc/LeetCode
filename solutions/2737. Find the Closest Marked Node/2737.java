class Solution {
  public int minimumDistance(int n, List<List<Integer>> edges, int s, int[] marked) {
    int ans = Integer.MAX_VALUE;
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (List<Integer> edge : edges) {
      final int u = edge.get(0);
      final int v = edge.get(1);
      final int w = edge.get(2);
      graph[u].add(new Pair<>(v, w));
    }

    int[] dist = dijkstra(graph, s);

    for (final int u : marked)
      ans = Math.min(ans, dist[u]);

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }

  private int[] dijkstra(List<Pair<Integer, Integer>>[] graph, int src) {
    int[] dist = new int[graph.length];
    Arrays.fill(dist, Integer.MAX_VALUE);
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
}
