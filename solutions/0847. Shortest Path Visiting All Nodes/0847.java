class Solution {
  public int shortestPathLength(int[][] graph) {
    final int n = graph.length;
    final int goal = (1 << n) - 1;

    int ans = 0;
    Queue<int[]> q = new LinkedList<>(); // {node, state (i-th bit)}
    boolean[][] seen = new boolean[n][1 << n];

    for (int i = 0; i < n; ++i)
      q.offer(new int[] {i, 1 << i});

    while (!q.isEmpty()) {
      for (int size = q.size(); size > 0; --size) {
        final int node = q.peek()[0];
        final int state = q.poll()[1];
        if (state == goal)
          return ans;
        if (seen[node][state])
          continue;
        seen[node][state] = true;
        for (final int child : graph[node])
          q.offer(new int[] {child, state | (1 << child)});
      }
      ++ans;
    }

    return -1;
  }
}
