class Solution {
  public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
    int[] ans = new int[queries.length];
    int[] dist = new int[n];
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i) {
      dist[i] = i;
      graph[i] = new ArrayList<>();
    }

    for (int i = 0; i < n - 1; ++i)
      graph[i].add(i + 1);

    for (int i = 0; i < queries.length; ++i) {
      final int u = queries[i][0];
      final int v = queries[i][1];
      graph[u].add(v);
      if (dist[u] + 1 < dist[v]) {
        dist[v] = dist[u] + 1;
        bfs(graph, v, dist);
      }
      ans[i] = dist[n - 1];
    }

    return ans;
  }

  // Performs a BFS to update the shortest distances from the given `start` node
  // to all other reachable nodes in the graph. It updates the `dist` vector
  // with the new shortest distances.
  private void bfs(List<Integer>[] graph, int start, int[] dist) {
    Queue<Integer> q = new LinkedList<>(Arrays.asList(start));
    while (!q.isEmpty()) {
      final int u = q.poll();
      for (final int v : graph[u]) {
        if (dist[u] + 1 < dist[v]) {
          dist[v] = dist[u] + 1;
          q.offer(v);
        }
      }
    }
  }
}
