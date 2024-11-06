class Solution {
  public int maximumScore(int[] scores, int[][] edges) {
    final int n = scores.length;
    int ans = -1;
    Queue<Integer>[] graph = new Queue[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new PriorityQueue<>((a, b) -> Integer.compare(scores[a], scores[b]));

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].offer(v);
      graph[v].offer(u);
      if (graph[u].size() > 3)
        graph[u].poll();
      if (graph[v].size() > 3)
        graph[v].poll();
    }

    // To find the target sequence: a - u - v - b, enumerate each edge (u, v),
    // and find a (u's child) and b (v's child). That's why we find the 3
    // children that have the highest scores because one of the 3 children is
    // guaranteed to be valid.
    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      for (final int a : graph[u])
        for (final int b : graph[v])
          if (a != b && a != v && b != u)
            ans = Math.max(ans, scores[a] + scores[u] + scores[v] + scores[b]);
    }

    return ans;
  }
}
