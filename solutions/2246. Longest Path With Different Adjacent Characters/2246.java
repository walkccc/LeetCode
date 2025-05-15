class Solution {
  public int longestPath(int[] parent, String s) {
    final int n = parent.length;
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int i = 1; i < n; ++i)
      graph[parent[i]].add(i);

    longestPathDownFrom(graph, 0, s);
    return ans;
  }

  private int ans = 0;

  private int longestPathDownFrom(List<Integer>[] graph, int u, final String s) {
    int max1 = 0;
    int max2 = 0;

    for (final int v : graph[u]) {
      final int res = longestPathDownFrom(graph, v, s);
      if (s.charAt(u) == s.charAt(v))
        continue;
      if (res > max1) {
        max2 = max1;
        max1 = res;
      } else if (res > max2) {
        max2 = res;
      }
    }

    ans = Math.max(ans, 1 + max1 + max2);
    return 1 + max1;
  }
}
