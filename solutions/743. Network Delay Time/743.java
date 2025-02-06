class Solution {
  public int networkDelayTime(int[][] times, int n, int k) {
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] time : times) {
      final int u = time[0] - 1;
      final int v = time[1] - 1;
      final int w = time[2];
      graph[u].add(new Pair<>(v, w));
    }

    return dijkstra(graph, k - 1);
  }

  private int dijkstra(List<Pair<Integer, Integer>>[] graph, int src) {
    int[] dist = new int[graph.length];
    Arrays.fill(dist, Integer.MAX_VALUE);

    dist[src] = 0;
    Queue<Pair<Integer, Integer>> minHeap =
        new PriorityQueue<>(Comparator.comparing(Pair::getKey)) {
          { offer(new Pair<>(dist[src], src)); } // (d, u)
        };

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

    final int maxDist = Arrays.stream(dist).max().getAsInt();
    return maxDist == Integer.MAX_VALUE ? -1 : maxDist;
  }
}
