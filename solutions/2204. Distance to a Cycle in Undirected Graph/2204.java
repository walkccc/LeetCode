class Solution {
  public int[] distanceToCycle(int n, int[][] edges) {
    int[] ans = new int[n];
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    // rank[i] := the minimum node that node i can reach with forward edges
    // Initialize with NO_RANK = -2 to indicate not visited.
    int[] rank = new int[n];
    Arrays.fill(rank, NO_RANK);
    List<Integer> cycle = new ArrayList<>();
    getRank(graph, 0, 0, rank, cycle);

    Queue<Integer> q = cycle.stream().collect(Collectors.toCollection(ArrayDeque::new));
    boolean[] seen = new boolean[n];
    for (final int u : cycle)
      seen[u] = true;

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final int u = q.poll();
        for (final int v : graph[u]) {
          if (seen[v])
            continue;
          q.offer(v);
          seen[v] = true;
          ans[v] = step;
        }
      }

    return ans;
  }

  private static final int NO_RANK = -2;

  // The minRank that u can reach with forward edges
  private int getRank(List<Integer>[] graph, int u, int currRank, int[] rank, List<Integer> cycle) {
    if (rank[u] != NO_RANK) // The rank is already determined
      return rank[u];

    rank[u] = currRank;
    int minRank = currRank;

    for (final int v : graph[u]) {
      // Visited || parent (that's why NO_RANK = -2 instead of -1)
      if (rank[u] == rank.length || rank[v] == currRank - 1)
        continue;
      final int nextRank = getRank(graph, v, currRank + 1, rank, cycle);
      // NextRank should > currRank if there's no cycle
      if (nextRank <= currRank)
        cycle.add(v);
      minRank = Math.min(minRank, nextRank);
    }

    rank[u] = rank.length; // Mark as visited.
    return minRank;
  }
}
