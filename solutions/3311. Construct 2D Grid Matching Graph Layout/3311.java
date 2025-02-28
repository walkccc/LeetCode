class Solution {
  public int[][] constructGridLayout(int n, int[][] edges) {
    List<Integer>[] graph = new ArrayList[n];

    for (int i = 0; i < n; i++)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    // Randomly choose a node with the minimum degree as the corner.
    int corner = 0;
    for (int i = 1; i < n; i++)
      if (graph[i].size() < graph[corner].size())
        corner = i;

    boolean[] seen = new boolean[n];
    seen[corner] = true;
    int[] firstRow = getFirstRow(graph, corner, seen);
    int cols = firstRow.length;
    int rows = n / cols;

    int[][] ans = new int[rows][cols];
    ans[0] = firstRow;

    for (int i = 1; i < rows; ++i)
      for (int j = 0; j < cols; ++j)
        for (final int v : graph[ans[i - 1][j]])
          if (!seen[v]) {
            ans[i][j] = v;
            seen[v] = true;
            break;
          }

    return ans;
  }

  private int[] getFirstRow(List<Integer>[] graph, int corner, boolean[] seen) {
    final int cornerDegree = graph[corner].size();
    List<Integer> row = new ArrayList<>(List.of(corner));
    // Continue appending neighbors until we hit another corner.
    while (row.size() == 1 || graph[row.get(row.size() - 1)].size() == cornerDegree + 1) {
      List<Integer> neighbors = graph[row.get(row.size() - 1)];
      Collections.sort(neighbors, (a, b) -> graph[a].size() - graph[b].size());
      for (final int v : neighbors)
        if (!seen[v] && (graph[v].size() == cornerDegree || graph[v].size() == cornerDegree + 1)) {
          row.add(v);
          seen[v] = true;
          break;
        }
    }
    return row.stream().mapToInt(Integer::intValue).toArray();
  }
}
