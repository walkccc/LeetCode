class Solution {
  public long minimumWeight(int n, int[][] edges, int src1, int src2, int dest) {
    List<Pair<Integer, Integer>>[] graph1 = new List[n];
    List<Pair<Integer, Integer>>[] graph2 = new List[n]; // reversed(graph1)

    for (int i = 0; i < n; ++i) {
      graph1[i] = new ArrayList<>();
      graph2[i] = new ArrayList<>();
    }

    for (int[] e : edges) {
      final int u = e[0];
      final int v = e[1];
      final int w = e[2];
      graph1[u].add(new Pair<>(v, w));
      graph2[v].add(new Pair<>(u, w));
    }

    long[] fromSrc1 = dijkstra(graph1, src1);
    long[] fromSrc2 = dijkstra(graph1, src2);
    long[] fromDest = dijkstra(graph2, dest);
    long ans = kMax;

    for (int i = 0; i < n; ++i) {
      if (fromSrc1[i] == kMax || fromSrc2[i] == kMax || fromDest[i] == kMax)
        continue;
      ans = Math.min(ans, fromSrc1[i] + fromSrc2[i] + fromDest[i]);
    }

    return ans == kMax ? -1 : ans;
  }

  private static long kMax = (long) 1e10;

  private long[] dijkstra(List<Pair<Integer, Integer>>[] graph, int src) {
    Queue<Pair<Long, Integer>> minHeap =
        new PriorityQueue<>(Comparator.comparing(Pair::getKey)); // (d, u)
    long[] dist = new long[graph.length];
    Arrays.fill(dist, kMax);
    minHeap.offer(new Pair<>(0L, src));
    while (!minHeap.isEmpty()) {
      final long d = minHeap.peek().getKey();
      final int u = minHeap.poll().getValue();
      if (dist[u] != kMax)
        continue;
      dist[u] = d;
      for (Pair<Integer, Integer> node : graph[u]) {
        final int v = node.getKey();
        final int w = node.getValue();
        minHeap.offer(new Pair<>(d + w, v));
      }
    }
    return dist;
  }
}
