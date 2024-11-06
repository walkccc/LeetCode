struct Node {
  int node = 0;  // the node number
  int time = 0;  // the time it got marked
};

struct Last2 {
  Node last1;  // the last marked node
  Node last2;  // the second last marked node
};

class Solution {
 public:
  // Similar to 3241. Time Taken to Mark All Nodes
  vector<int> lastMarkedNodes(vector<vector<int>>& edges) {
    const int n = edges.size() + 1;
    vector<int> ans(n);
    vector<vector<int>> tree(n);
    // dp[i] := the last marked two nodes for subtree rooted at node i, where
    // each node contains the time it got marked
    vector<Last2> dp(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    dfs(tree, 0, /*prev=*/-1, dp);
    reroot(tree, 0, /*prev=*/-1, /*last=*/Node(), dp, ans);
    return ans;
  }

 private:
  // Performs a DFS traversal of the subtree rooted at node `u`, computes the
  // time taken to mark all nodes in the subtree, records the last two marked
  // nodes, and returns the last marked node.
  //
  // These values are used later in the rerooting process.
  Node dfs(const vector<vector<int>>& tree, int u, int prev,
           vector<Last2>& dp) {
    Node last1(u, 0);
    Node last2;
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      Node child = dfs(tree, v, u, dp);
      const int time = child.time + 1;
      if (time > last1.time) {
        last2 = last1;
        last1 = Node(child.node, time);
      } else if (time > last2.time) {
        last2 = Node(child.node, time);
      }
    }
    dp[u] = {last1, last2};
    return last1;
  }

  // Reroots the tree at node `u` and updates the answer array, where `last`
  // is the last marked node that doesn't go through `u`'s subtree.
  void reroot(const vector<vector<int>>& tree, int u, int prev,
              const Node& last, vector<Last2>& dp, vector<int>& ans) {
    ans[u] = last.time > dp[u].last1.time ? last.node : dp[u].last1.node;
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      Node newLast(last.node, last.time + 1);
      if (dp[u].last1.node == dp[v].last1.node) {
        const int alternativeTime = 1 + dp[u].last2.time;
        if (alternativeTime > newLast.time)
          newLast = Node(dp[u].last2.node, alternativeTime);
      } else {
        const int alternativeTime = 1 + dp[u].last1.time;
        if (alternativeTime > newLast.time)
          newLast = Node(dp[u].last1.node, alternativeTime);
      }
      reroot(tree, v, u, newLast, dp, ans);
    }
  }
};
