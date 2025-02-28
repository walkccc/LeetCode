class Solution {
  // Similar to 3241. Time Taken to Mark All Nodes
  public int[] lastMarkedNodes(int[][] edges) {
    final int n = edges.length + 1;
    int[] ans = new int[n];
    List<Integer>[] tree = new List[n];
    // dp[i] := the last marked two nodes for subtree rooted at node i, where
    // each node contains the time it got marked
    Last2[] dp = new Last2[n];

    for (int i = 0; i < n; ++i) {
      tree[i] = new ArrayList<>();
      dp[i] = new Last2();
    }

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    dfs(tree, 0, /*prev=*/-1, dp);
    reroot(tree, 0, /*prev=*/-1, /*last=*/new Node(), dp, ans);
    return ans;
  }

  private record Node(int node, int time) {
    Node() {
      this(0, 0);
    }
  }

  private record Last2(Node last1, Node last2) {
    Last2() {
      this(new Node(), new Node());
    }
  }

  // Performs a DFS traversal of the subtree rooted at node `u`, computes the
  // time taken to mark all nodes in the subtree, records the last two marked
  // nodes, and returns the last marked node.
  //
  // These values are used later in the rerooting process.
  private Node dfs(List<Integer>[] tree, int u, int prev, Last2[] dp) {
    Node last1 = new Node(u, 0);
    Node last2 = new Node();
    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      Node child = dfs(tree, v, u, dp);
      final int time = child.time() + 1;
      if (time > last1.time) {
        last2 = last1;
        last1 = new Node(child.node(), time);
      } else if (time > last2.time) {
        last2 = new Node(child.node(), time);
      }
    }
    dp[u] = new Last2(last1, last2);
    return last1;
  }

  // Reroots the tree at node `u` and updates the answer array, where `last`
  // is the last marked node that doesn't go through `u`'s subtree.
  private void reroot(List<Integer>[] tree, int u, int prev, Node last, Last2[] dp, int[] ans) {
    ans[u] = last.time() > dp[u].last1().time() ? last.node() : dp[u].last1().node();
    for (final int v : tree[u]) {
      if (v == prev)
        continue;
      Node newLast = new Node(last.node(), last.time() + 1); // 1 := u -> v
      if (dp[u].last1().node() == dp[v].last1().node()) {
        final int alternativeTime = 1 + dp[u].last2().time();
        if (alternativeTime > newLast.time())
          newLast = new Node(dp[u].last2().node(), alternativeTime);
      } else {
        final int alternativeTime = 1 + dp[u].last1().time();
        if (alternativeTime > newLast.time())
          newLast = new Node(dp[u].last1().node(), alternativeTime);
      }
      reroot(tree, v, u, newLast, dp, ans);
    }
  }
}
