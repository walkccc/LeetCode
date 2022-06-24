class Solution {
  public int minMalwareSpread(int[][] graph, int[] initial) {
    int ans = 0;
    int minCount = graph.length;

    Arrays.sort(initial);

    for (final int i : initial) {
      final int count = bfs(graph, i, initial);
      if (count < minCount) {
        minCount = count;
        ans = i;
      }
    }

    return ans;
  }

  private int bfs(int[][] graph, int removed, int[] initial) {
    Queue<Integer> q = new ArrayDeque<>();
    boolean[] seen = new boolean[graph.length];
    seen[removed] = true;

    int count = 0;

    for (final int i : initial)
      if (i != removed) {
        q.offer(i);
        seen[i] = true;
      }

    while (!q.isEmpty()) {
      final int u = q.poll();
      ++count;
      for (int i = 0; i < graph.length; ++i) {
        if (seen[i])
          continue;
        if (i != u && graph[i][u] == 1) {
          q.offer(i);
          seen[i] = true;
        }
      }
    }

    return count;
  }
}
