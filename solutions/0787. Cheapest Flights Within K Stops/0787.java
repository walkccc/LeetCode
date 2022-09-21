class Solution {
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    List<Pair<Integer, Integer>>[] graph = new List[n];
    // (d, u, stops)
    Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
    int[][] dist = new int[n][k + 2];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] f : flights) {
      final int u = f[0];
      final int v = f[1];
      final int w = f[2];
      graph[u].add(new Pair<>(v, w));
    }

    minHeap.offer(new int[] {0, src, k + 1}); // start with node src with d == 0
    dist[src][k + 1] = 0;

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek()[0];
      final int u = minHeap.peek()[1];
      final int stops = minHeap.poll()[2];
      if (u == dst)
        return d;
      if (stops > 0)
        for (Pair<Integer, Integer> node : graph[u]) {
          final int v = node.getKey();
          final int w = node.getValue();
          final int newDist = d + w;
          if (newDist < dist[v][stops - 1]) {
            dist[v][stops - 1] = newDist;
            minHeap.offer(new int[] {d + w, v, stops - 1});
          }
        }
    }

    return -1;
  }
}
