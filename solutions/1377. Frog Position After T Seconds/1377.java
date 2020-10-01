class Solution {
  public double frogPosition(int n, int[][] edges, int t, int target) {
    double[] prob = new double[n + 1];
    boolean[] visited = new boolean[n + 1];
    Queue<Integer> queue = new LinkedList<>();
    List<Integer>[] graph = new List[n + 1];

    prob[1] = 1.0;
    visited[1] = true;
    queue.add(1);

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (final int[] edge : edges) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    for (int i = 0; i < t; ++i) {
      for (int j = queue.size(); j > 0; --j) {
        int curr = queue.poll();
        int children = 0;
        for (int child : graph[curr])
          if (!visited[child])
            ++children;
        for (int child : graph[curr])
          if (!visited[child]) {
            visited[child] = true;
            prob[child] = prob[curr] / children;
            queue.add(child);
          }
        if (children > 0)
          prob[curr] = 0.0;
      }
    }

    return prob[target];
  }
}