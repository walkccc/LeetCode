class Solution {
  public int shortestPathLength(int[][] graph) {
    final int n = graph.length;
    final int goal = (1 << n) - 1;
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(); // (u, state)
    boolean[][] seen = new boolean[n][1 << n];

    for (int i = 0; i < n; ++i)
      q.offer(new Pair<>(i, 1 << i));

    for (int step = 0; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int u = q.peek().getKey();
        final int state = q.poll().getValue();
        if (state == goal)
          return step;
        if (seen[u][state])
          continue;
        seen[u][state] = true;
        for (final int v : graph[u])
          q.offer(new Pair<>(v, state | 1 << v));
      }

    return -1;
  }
}
