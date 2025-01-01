class Solution {
  public int[] gardenNoAdj(int n, int[][] paths) {
    int[] ans = new int[n]; // ans[i] := 1, 2, 3, or 4
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] path : paths) {
      final int u = path[0] - 1;
      final int v = path[1] - 1;
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int u = 0; u < n; ++u) {
      int used = 0;
      for (final int v : graph[u])
        used |= 1 << ans[v];
      ans[u] = getFirstUnusedType(used);
    }

    return ans;
  }

  private int getFirstUnusedType(int used) {
    for (int type = 1; type <= 4; ++type)
      if ((used >> type & 1) == 0)
        return type;
    throw new IllegalArgumentException();
  }
}
