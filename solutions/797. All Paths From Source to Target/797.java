class Solution {
  public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
    List<List<Integer>> ans = new ArrayList<>();
    dfs(graph, 0, new ArrayList<>(List.of(0)), ans);
    return ans;
  }

  private void dfs(int[][] graph, int u, List<Integer> path, List<List<Integer>> ans) {
    if (u == graph.length - 1) {
      ans.add(new ArrayList<>(path));
      return;
    }

    for (final int v : graph[u]) {
      path.add(v);
      dfs(graph, v, path, ans);
      path.remove(path.size() - 1);
    }
  }
}
