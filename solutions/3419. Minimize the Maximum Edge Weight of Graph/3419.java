class Solution {
  public int minMaxWeight(int n, int[][] pairs, int threshold) {
    final int MAX = 1_000_000;
    List<Pair<Integer, Integer>>[] reversedGraph = new List[n];

    for (int i = 0; i < n; i++)
      reversedGraph[i] = new ArrayList<>();

    for (int[] pair : pairs) {
      final int u = pair[0];
      final int v = pair[1];
      final int w = pair[2];
      reversedGraph[v].add(new Pair<>(u, w));
    }

    int l = 1;
    int r = MAX + 1;

    while (l < r) {
      final int m = (l + r) / 2;
      if (dfs(reversedGraph, 0, m, new boolean[n]) == n)
        r = m;
      else
        l = m + 1;
    }

    return l == (MAX + 1) ? -1 : l;
  }

  // Returns the number of nodes reachable from u with weight <= maxWeight.
  private int dfs(List<Pair<Integer, Integer>>[] reversedGraph, int u, int maxWeight,
                  boolean[] seen) {
    int res = 1;
    seen[u] = true;
    for (Pair<Integer, Integer> pair : reversedGraph[u]) {
      final int v = pair.getKey();
      final int w = pair.getValue();
      if (w > maxWeight || seen[v])
        continue;
      res += dfs(reversedGraph, v, maxWeight, seen);
    }
    return res;
  }
}
