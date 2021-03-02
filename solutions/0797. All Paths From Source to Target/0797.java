class Solution {
  public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> path = new ArrayList<>(Arrays.asList(0));

    dfs(graph, 0, path, ans);

    return ans;
  }

  private void dfs(int[][] graph, int node, List<Integer> path, List<List<Integer>> ans) {
    if (node == graph.length - 1) {
      ans.add(new ArrayList<>(path));
      return;
    }

    for (final int child : graph[node]) {
      path.add(child);
      dfs(graph, child, path, ans);
      path.remove(path.size() - 1);
    }
  }
}
