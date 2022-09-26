class Solution {
  public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
    List<Integer> rowOrder = topologicalSort(rowConditions, k);
    if (rowOrder.isEmpty())
      return new int[][] {};

    List<Integer> colOrder = topologicalSort(colConditions, k);
    if (colOrder.isEmpty())
      return new int[][] {};

    int[][] ans = new int[k][k];
    int[] nodeToRowIndex = new int[k + 1];

    for (int i = 0; i < k; ++i)
      nodeToRowIndex[rowOrder.get(i)] = i;

    for (int j = 0; j < k; ++j) {
      final int node = colOrder[j];
      final int i = nodeToRowIndex[node];
      ans[i][j] = node;
    }

    return ans;
  }

  private List<Integer> topologicalSort(int[][] conditions, int n) {
    List<Integer> order = new ArrayList<>();
    List<Integer>[] graph = new List[n + 1];
    int[] inDegree = new int[n + 1];
    Queue<Integer> q = new ArrayDeque<>();

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    // build graph
    for (int[] condition : conditions) {
      final int u = condition[0];
      final int v = condition[1];
      graph[u].add(v);
      ++inDegree[v];
    }

    // topology
    for (int i = 1; i <= n; ++i)
      if (inDegree[i] == 0)
        q.offer(i);

    while (!q.isEmpty()) {
      final int u = q.poll();
      order.add(u);
      for (final int v : graph[u])
        if (--inDegree[v] == 0)
          q.offer(v);
    }

    return order.size() == n ? order : new ArrayList<>();
  }
}
