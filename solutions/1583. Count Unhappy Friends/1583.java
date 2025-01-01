class Solution {
  public int unhappyFriends(int n, int[][] preferences, int[][] pairs) {
    int ans = 0;
    int[] matches = new int[n];
    Map<Integer, Integer>[] prefer = new Map[n];

    for (int[] pair : pairs) {
      final int x = pair[0];
      final int y = pair[1];
      matches[x] = y;
      matches[y] = x;
    }

    for (int i = 0; i < n; ++i)
      prefer[i] = new HashMap<>();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n - 1; ++j)
        prefer[i].put(preferences[i][j], j);

    for (int x = 0; x < n; ++x)
      for (final int u : preferences[x]) {
        final int y = matches[x];
        final int v = matches[u];
        if (prefer[x].get(u) < prefer[x].get(y) && prefer[u].get(x) < prefer[u].get(v)) {
          ++ans;
          break;
        }
      }

    return ans;
  }
}
