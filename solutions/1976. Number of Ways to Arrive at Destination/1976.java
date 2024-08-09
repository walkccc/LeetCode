class Solution {
  public int countPaths(int n, int[][] roads) {
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] road : roads) {
      final int u = road[0];
      final int v = road[1];
      final int w = road[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    return dijkstra(graph, 0, n - 1);
  }

  private int dijkstra(List<Pair<Integer, Integer>>[] graph, int src, int dst) {
    final int kMod = 1_000_000_007;
    long[] ways = new long[graph.length];
    Arrays.fill(ways, 0);
    long[] dist = new long[graph.length];
    Arrays.fill(dist, Long.MAX_VALUE);
    Queue<Pair<Long, Integer>> minHeap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));

    ways[src] = 1;
    dist[src] = 0;
    minHeap.offer(new Pair<>(dist[src], src));

    while (!minHeap.isEmpty()) {
      final long d = minHeap.peek().getKey();
      final int u = minHeap.poll().getValue();
      if (d > dist[u])
        continue;
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        if (d + w < dist[v]) {
          dist[v] = d + w;
          ways[v] = ways[u];
          minHeap.offer(new Pair<>(dist[v], v));
        } else if (d + w == dist[v]) {
          ways[v] += ways[u];
          ways[v] %= kMod;
        }
      }
    }

    return (int) ways[dst];
  }
}
