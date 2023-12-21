class Solution {
  public int minCost(int maxTime, int[][] edges, int[] passingFees) {
    final int n = passingFees.length;
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int t = edge[2];
      graph[u].add(new Pair<>(v, t));
      graph[v].add(new Pair<>(u, t));
    }

    return dijkstra(graph, 0, n - 1, maxTime, passingFees);
  }

  private int dijkstra(List<Pair<Integer, Integer>>[] graph, int src, int dst, int maxTime,
                       int[] passingFees) {
    int[] cost = new int[graph.length]; // cost[i] := the minimum cost to reach the i-th city
    int[] dist = new int[graph.length]; // dist[i] := the minimum distance to reach the i-th city
    Arrays.fill(cost, Integer.MAX_VALUE);
    Arrays.fill(dist, maxTime + 1);
    // (cost[u], dist[u], u)
    Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);

    cost[0] = passingFees[0];
    dist[0] = 0;
    minHeap.offer(new int[] {cost[src], dist[src], src});

    while (!minHeap.isEmpty()) {
      final int currCost = minHeap.peek()[0];
      final int d = minHeap.peek()[1];
      final int u = minHeap.poll()[2];
      if (u == dst)
        return cost[dst];
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        if (d + w > maxTime)
          continue;
        // Go from x -> y
        if (currCost + passingFees[v] < cost[v]) {
          cost[v] = currCost + passingFees[v];
          dist[v] = d + w;
          minHeap.offer(new int[] {cost[v], dist[v], v});
        } else if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.offer(new int[] {currCost + passingFees[v], dist[v], v});
        }
      }
    }

    return -1;
  }
}
