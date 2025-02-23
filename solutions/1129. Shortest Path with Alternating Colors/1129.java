enum Color { kInit, kRed, kBlue }

class Solution {
  public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
    int[] ans = new int[n];
    Arrays.fill(ans, -1);
    // graph[u] := [(v, edgeColor)]
    List<Pair<Integer, Color>>[] graph = new List[n];
    // [(u, prevColor)]
    Queue<Pair<Integer, Color>> q = new ArrayDeque<>(List.of(new Pair<>(0, Color.kInit)));

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : redEdges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(new Pair<>(v, Color.kRed));
    }

    for (int[] edge : blueEdges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(new Pair<>(v, Color.kBlue));
    }

    for (int step = 0; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int u = q.peek().getKey();
        Color prevColor = q.poll().getValue();
        ans[u] = ans[u] == -1 ? step : ans[u];
        for (int i = 0; i < graph[u].size(); ++i) {
          Pair<Integer, Color> node = graph[u].get(i);
          final int v = node.getKey();
          Color edgeColor = node.getValue();
          if (v == -1 || edgeColor == prevColor)
            continue;
          q.add(new Pair<>(v, edgeColor));
          // Mark (u, v) as used.
          graph[u].set(i, new Pair<>(-1, edgeColor));
        }
      }

    return ans;
  }
}
