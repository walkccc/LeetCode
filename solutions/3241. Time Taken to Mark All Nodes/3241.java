class Solution {
  public int[] timeTaken(int[][] edges) {
    final int n = edges.length + 1;
    int[] ans = new int[n];
    List<Integer>[] tree = new List[n];
    // dp[i] := the top two nodes with maximum times to mark all nodes in the
    // subtree rooted at node i
    Top2[] dp = new Top2[n];

    for (int i = 0; i < n; ++i) {
      tree[i] = new ArrayList<>();
      dp[i] = new Top2();
    }

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    dfs(tree, 0, /*prev=*/-1, dp);
    reroot(tree, 0, /*prev=*/-1, /*maxTime=*/0, dp, ans);
    return ans;
  }

  private record T(int node, int time) {
    T() {
      this(-1, 0);
    }
  }

  private record Top2(T max1, T max2) {
    Top2() {
      this(new T(), new T());
    }
  }

  // Return the time taken to mark node u.
  private int getTime(int u) {
    return u % 2 == 0 ? 2 : 1;
  }

  // Performs a DFS traversal of the tree, computing the maximum time to mark
  // all nodes in the subtree rooted at node u.
  //
  // This function calculates and stores the top two maximum times for each
  // node's subtree. These values are used later in the rerooting process.
  private int dfs(List<Integer>[] tree, int u, int prev, Top2[] dp) {
    T max1 = new T();
    T max2 = new T();
    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      final int time = dfs(tree, v, u, dp) + getTime(v);
      if (time >= max1.time()) {
        max2 = max1;
        max1 = new T(v, time);
      } else if (time > max2.time()) {
        max2 = new T(v, time);
      }
    }
    dp[u] = new Top2(max1, max2);
    return max1.time();
  }

  // Reroots the tree at node `u` and updates the answer array, where `maxTime`
  // is the longest path that doesn't go through `u`'s subtree.
  private void reroot(List<Integer>[] tree, int u, int prev, int maxTime, Top2[] dp, int[] ans) {
    ans[u] = Math.max(maxTime, dp[u].max1().time());
    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      final int newMaxTime =
          getTime(u) +
          Math.max(maxTime, dp[u].max1().node() == v ? dp[u].max2().time() : dp[u].max1().time());
      reroot(tree, v, u, newMaxTime, dp, ans);
    }
  }
}
