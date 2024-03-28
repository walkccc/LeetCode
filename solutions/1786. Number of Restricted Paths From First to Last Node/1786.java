class Solution {
  public int countRestrictedPaths(int n, int[][] edges) {
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0] - 1;
      final int v = edge[1] - 1;
      final int w = edge[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    return dijkstra(graph, 0, n - 1);
  }

  private int dijkstra(List<Pair<Integer, Integer>>[] graph, int src, int dst) {
    final int kMod = 1_000_000_007;
    // ways[i] := the number of restricted path from i to n
    long[] ways = new long[graph.length];
    // dist[i] := the distance to the last node of i
    long[] dist = new long[graph.length];
    Arrays.fill(dist, Long.MAX_VALUE);
    // (d, u)
    Queue<Pair<Long, Integer>> minHeap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));

    ways[dst] = 1;
    dist[dst] = 0;
    minHeap.offer(new Pair<>(dist[dst], dst));

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
          minHeap.offer(new Pair<>(dist[v], v));
        }
        if (dist[v] < dist[u]) {
          ways[u] += ways[v];
          ways[u] %= kMod;
        }
      }
    }

    return (int) ways[src];
  }
}
