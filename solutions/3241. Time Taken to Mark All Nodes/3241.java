class Solution {
  public int[] timeTaken(int[][] edges) {
    final int n = edges.length + 1;
    int[] ans = new int[n];
    List<Integer>[] tree = new List[n];
    // dp[i] := the top two direct child nodes for subtree rooted at node i,
    // where each node contains the time taken to mark the entire subtree rooted
    // at the node itself
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

  private record Node(int node, int time) {
    Node() {
      this(0, 0);
    }
  }

  private record Top2(Node max1, Node max2) {
    Top2() {
      this(new Node(), new Node());
    }
  }

  // Return the time taken to mark node u.
  private int getTime(int u) {
    return u % 2 == 0 ? 2 : 1;
  }

  // Performs a DFS traversal of the subtree rooted at node `u`, computes the
  // time taken to mark all nodes in the subtree, records the top two direct
  // child nodes, where the time taken to mark the subtree rooted at each of the
  // child nodes is maximized, and returns the top child node.
  //
  // These values are used later in the rerooting process.
  private int dfs(List<Integer>[] tree, int u, int prev, Top2[] dp) {
    Node max1 = new Node();
    Node max2 = new Node();
    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      final int time = dfs(tree, v, u, dp) + getTime(v);
      if (time >= max1.time()) {
        max2 = max1;
        max1 = new Node(v, time);
      } else if (time > max2.time()) {
        max2 = new Node(v, time);
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
