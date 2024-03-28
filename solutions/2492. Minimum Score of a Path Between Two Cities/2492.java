class Solution {
  public int minScore(int n, int[][] roads) {
    int ans = Integer.MAX_VALUE;
    List<Pair<Integer, Integer>>[] graph = new List[n]; // graph[u] := [(v, distance)]
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(0));
    boolean[] seen = new boolean[n];
    seen[0] = true;

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (final int[] r : roads) {
      final int u = r[0] - 1;
      final int v = r[1] - 1;
      final int distance = r[2];
      graph[u].add(new Pair<>(v, distance));
      graph[v].add(new Pair<>(u, distance));
    }

    while (!q.isEmpty()) {
      final int u = q.poll();
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int d = pair.getValue();
        ans = Math.min(ans, d);
        if (seen[v])
          continue;
        q.offer(v);
        seen[v] = true;
      }
    }

    return ans;
  }
}
