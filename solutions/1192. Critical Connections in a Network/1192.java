class Solution {
  public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (List<Integer> connection : connections) {
      final int u = connection.get(0);
      final int v = connection.get(1);
      graph[u].add(v);
      graph[v].add(u);
    }

    // rank[i] := the minimum node that node i can reach with forward edges
    // Initialize with NO_RANK = -2 to indicate not visited.
    int[] rank = new int[n];
    Arrays.fill(rank, NO_RANK);
    getRank(graph, 0, 0, rank, ans);
    return ans;
  }

  private static final int NO_RANK = -2;

  // Gets the minimum rank that u can reach with forward edges.
  private int getRank(List<Integer>[] graph, int u, int myRank, int[] rank,
                      List<List<Integer>> ans) {
    if (rank[u] != NO_RANK) // The rank is already been determined.
      return rank[u];

    rank[u] = myRank;
    int minRank = myRank;

    for (final int v : graph[u]) {
      // visited || parent (that's why NO_RANK = -2 instead of -1)
      if (rank[u] == rank.length || rank[v] == myRank - 1)
        continue;
      final int nextRank = getRank(graph, v, myRank + 1, rank, ans);
      // (u, v) is the only way for u go to v.
      if (nextRank == myRank + 1)
        ans.add(Arrays.asList(u, v));
      minRank = Math.min(minRank, nextRank);
    }

    rank[u] = rank.length; // Mark as visited.
    return minRank;
  }
}
