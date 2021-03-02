class Solution {
  public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer>[] graph = new List[n];
    // rank[i] := min node that node i can reach w/ forward edges
    // initialize to NO_RANK = -2 indicates not visited
    int[] rank = new int[n];
    Arrays.fill(rank, NO_RANK);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (List<Integer> conn : connections) {
      graph[conn.get(0)].add(conn.get(1));
      graph[conn.get(1)].add(conn.get(0));
    }

    dfs(graph, 0, 0, rank, ans);

    return ans;
  }

  private static final int NO_RANK = -2;

  // the minRank that node can reach w/ forward edges
  private int dfs(
      List<Integer>[] graph, int node, int myRank, int[] rank, List<List<Integer>> ans) {
    if (rank[node] != NO_RANK) // the rank is already been determined
      return rank[node];

    rank[node] = myRank;
    int minRank = myRank;

    for (final int child : graph[node]) {
      // visited || parent (that's why NO_RANK = -2 instead of -1)
      if (rank[node] == rank.length || rank[child] == myRank - 1)
        continue;
      final int childRank = dfs(graph, child, myRank + 1, rank, ans);
      // path(node, child) is the only way for node go to child
      if (childRank == myRank + 1)
        ans.add(Arrays.asList(node, child));
      minRank = Math.min(minRank, childRank);
    }

    rank[node] = rank.length; // mark as visited

    return minRank;
  }
}
