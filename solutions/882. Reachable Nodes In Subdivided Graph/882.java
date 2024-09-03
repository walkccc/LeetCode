class Solution {
  public int reachableNodes(int[][] edges, int maxMoves, int n) {
    List<Pair<Integer, Integer>>[] graph = new List[n];
    // (d, u)
    Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
    int[] dist = new int[n];
    Arrays.fill(dist, maxMoves + 1);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int cnt = edge[2];
      graph[u].add(new Pair<>(v, cnt));
      graph[v].add(new Pair<>(u, cnt));
    }

    final int reachableNodes = dijkstra(graph, 0, maxMoves, dist);
    int reachableSubnodes = 0;

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int cnt = edge[2];
      // the number of reachable nodes of `edge` from `u`
      final int a = dist[u] > maxMoves ? 0 : Math.min(maxMoves - dist[u], cnt);
      // the number of reachable nodes of `edge` from `v`
      final int b = dist[v] > maxMoves ? 0 : Math.min(maxMoves - dist[v], cnt);
      reachableSubnodes += Math.min(a + b, cnt);
    }

    return reachableNodes + reachableSubnodes;
  }

  private int dijkstra(List<Pair<Integer, Integer>>[] graph, int src, int maxMoves, int[] dist) {
    // (d, u)
    Queue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>(Comparator.comparing(Pair::getKey));

    dist[src] = 0;
    minHeap.offer(new Pair<>(dist[src], src));

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek().getKey();
      final int u = minHeap.poll().getValue();
      // Already took `maxMoves` to reach `u`, so can't explore anymore.
      if (d >= maxMoves)
        break;
      if (d > dist[u])
        continue;
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        if (d + w + 1 < dist[v]) {
          dist[v] = d + w + 1;
          minHeap.offer(new Pair<>(dist[v], v));
        }
      }
    }

    return (int) Arrays.stream(dist).filter(d -> d <= maxMoves).count();
  }
}
