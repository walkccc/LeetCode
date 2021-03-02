class Solution {
  public int minimumSemesters(int N, int[][] relations) {
    List<Integer>[] graph = new List[N + 1];
    int[] inDegree = new int[N + 1];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    // build graph
    for (int[] r : relations) {
      final int out = r[0];
      final int in = r[1];
      graph[out].add(in);
      ++inDegree[in];
    }

    // topology
    int ans = 0;
    Queue<Integer> q = new LinkedList<>();

    for (int i = 1; i <= N; ++i)
      if (inDegree[i] == 0)
        q.offer(i);

    while (!q.isEmpty()) {
      for (int size = q.size(); size > 0; --size) {
        final int out = q.poll();
        --N;
        for (final int in : graph[out])
          if (--inDegree[in] == 0)
            q.offer(in);
      }
      ++ans;
    }

    return N == 0 ? ans : -1;
  }
}
