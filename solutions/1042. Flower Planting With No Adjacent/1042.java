class Solution {
  public int[] gardenNoAdj(int n, int[][] paths) {
    int[] ans = new int[n]; // ans[i] := 1, 2, 3, or 4
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] p : paths) {
      final int u = p[0] - 1;
      final int v = p[1] - 1;
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int i = 0; i < n; ++i) {
      boolean[] used = new boolean[5];
      for (final int v : graph[i])
        used[ans[v]] = true;
      for (int type = 1; type < 5; ++type)
        if (!used[type]) {
          ans[i] = type;
          break;
        }
    }

    return ans;
  }
}
