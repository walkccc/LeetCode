class Solution {
  public long minimumWeight(int n, int[][] edges, int src1, int src2, int dest) {
    List<Pair<Integer, Integer>>[] graph = new List[n];
    List<Pair<Integer, Integer>>[] reversedGraph = new List[n];

    for (int i = 0; i < n; ++i) {
      graph[i] = new ArrayList<>();
      reversedGraph[i] = new ArrayList<>();
    }

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int w = edge[2];
      graph[u].add(new Pair<>(v, w));
      reversedGraph[v].add(new Pair<>(u, w));
    }

    long[] fromSrc1 = dijkstra(graph, src1);
    long[] fromSrc2 = dijkstra(graph, src2);
    long[] fromDest = dijkstra(reversedGraph, dest);
    long ans = MAX;

    for (int i = 0; i < n; ++i) {
      if (fromSrc1[i] == MAX || fromSrc2[i] == MAX || fromDest[i] == MAX)
        continue;
      ans = Math.min(ans, fromSrc1[i] + fromSrc2[i] + fromDest[i]);
    }

    return ans == MAX ? -1 : ans;
  }

  private static long MAX = (long) 1e10;

  private long[] dijkstra(List<Pair<Integer, Integer>>[] graph, int src) {
    long[] dist = new long[graph.length];
    Arrays.fill(dist, MAX);

    dist[src] = 0;
    Queue<Pair<Long, Integer>> minHeap =
        new PriorityQueue<>(Comparator.comparingLong(Pair::getKey)) {
          {
            offer(new Pair<>(dist[src], src)); // (d, u)
          }
        };

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
      }
    }

    return dist;
  }
}
