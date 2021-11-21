class Solution {
  public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer>[] graph = new List[n];
    // rank[i] := min node that node i can reach w/ forward edges
    // initialize to NO_RANK = -2 indicates not visited
    int[] rank = new int[n];
    Arrays.fill(rank, NO_RANK);

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (List<Integer> conn : connections) {
      graph[conn.get(0)].add(conn.get(1));
      graph[conn.get(1)].add(conn.get(0));
    }

    dfs(graph, 0, 0, rank, ans);

    return ans;
  }

  private static final int NO_RANK = -2;

  // the minRank that u can reach w/ forward edges
  private int dfs(List<Integer>[] graph, int u, int myRank, int[] rank, List<List<Integer>> ans) {
    if (rank[u] != NO_RANK) // the rank is already been determined
      return rank[u];

    rank[u] = myRank;
    int minRank = myRank;

    for (final int v : graph[u]) {
      // visited || parent (that's why NO_RANK = -2 instead of -1)
      if (rank[u] == rank.length || rank[v] == myRank - 1)
        continue;
      final int vRank = dfs(graph, v, myRank + 1, rank, ans);
      // path(u, v) is the only way for u go to v
      if (vRank == myRank + 1)
        ans.add(Arrays.asList(u, v));
      minRank = Math.min(minRank, vRank);
    }

    rank[u] = rank.length; // mark as visited

    return minRank;
  }
}
