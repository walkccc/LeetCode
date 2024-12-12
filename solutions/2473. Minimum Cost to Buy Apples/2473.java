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
    long[] forwardCost = new long[graph.length];
    long[] totalCost = new long[graph.length];
    Arrays.fill(forwardCost, Long.MAX_VALUE);
    Arrays.fill(totalCost, Long.MAX_VALUE);
    forwardCost[i] = 0;
    Queue<Integer> q = new LinkedList<>(Arrays.asList(i));

    while (!q.isEmpty()) {
      final int u = q.poll();
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        final long nextCost = forwardCost[u] + w;
        if (nextCost >= forwardCost[v])
          continue;
        forwardCost[v] = nextCost;
        // Take apple at city v and return back to city i.
        totalCost[v] = (k + 1) * nextCost + appleCost[v];
        q.offer(v);
      }
    }

    return Math.min(appleCost[i], Arrays.stream(totalCost).min().getAsLong());
  }
}
