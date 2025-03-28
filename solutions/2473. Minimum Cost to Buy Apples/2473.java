class Solution {
  public long[] minCost(int n, int[][] roads, int[] appleCost, int k) {
    long[] ans = new long[n];
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] road : roads) {
      final int u = road[0] - 1;
      final int v = road[1] - 1;
      final int w = road[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    for (int i = 0; i < n; ++i)
      ans[i] = dijkstra(graph, i, appleCost, k);

    return ans;
  }

  private long dijkstra(List<Pair<Integer, Integer>>[] graph, int i, int[] appleCost, int k) {
    long ans = Long.MAX_VALUE;
    long[] dist = new long[graph.length];
    Arrays.fill(dist, Long.MAX_VALUE);

    dist[i] = 0;
    Queue<Pair<Long, Integer>> minHeap =
        new PriorityQueue<>(Comparator.comparingLong(Pair::getKey)) {
          { offer(new Pair<>(dist[i], i)); } // (d, u)
        };

    while (!minHeap.isEmpty()) {
      final long d = minHeap.peek().getKey();
      final int u = minHeap.poll().getValue();
      if (d > dist[u])
        continue;
      ans = Math.min(ans, appleCost[u] + (k + 1) * d);
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.offer(new Pair<>(dist[v], v));
        }
      }
    }

    return ans;
  }
}
