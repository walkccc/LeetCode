class Solution {
  public int countComponents(int n, int[][] edges) {
    int ans = 0;
    List<Integer>[] graph = new List[n];
    Set<Integer> seen = new HashSet<>();

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (final int[] edge : edges) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    for (int i = 0; i < n; ++i)
      if (seen.add(i)) {
        dfs(graph, seen, i);
        ++ans;
      }

    return ans;
  }

  private void dfs(List<Integer>[] graph, Set<Integer> seen, int i) {
    for (final int neighbor : graph[i])
      if (seen.add(neighbor))
        dfs(graph, seen, neighbor);
  }
}