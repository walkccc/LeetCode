struct Node {
  int node = 0;  // the node number
  int time = 0;  // the time taken to mark the entire subtree rooted at the node
};

struct Top2 {
  // the direct child node, where the time taken to mark the entire subtree
  // rooted at the node is the maximum
  Node top1;
  // the direct child node, where the time taken to mark the entire subtree
  // rooted at the node is the second maximum
  Node top2;
};

class Solution {
 public:
  vector<int> timeTaken(vector<vector<int>>& edges) {
    const int n = edges.size() + 1;
    vector<int> ans(n);
    vector<vector<int>> tree(n);
    // dp[i] := the top two direct child nodes for subtree rooted at node i,
    // where each node contains the time taken to mark the entire subtree rooted
    // at the node itself
    vector<Top2> dp(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    dfs(tree, 0, /*prev=*/-1, dp);
    reroot(tree, 0, /*prev=*/-1, /*maxTime=*/0, dp, ans);
    return ans;
  }

 private:
  // Return the time taken to mark node u.
  int getTime(int u) {
    return u % 2 == 0 ? 2 : 1;
  }

  // Performs a DFS traversal of the subtree rooted at node `u`, computes the
  // time taken to mark all nodes in the subtree, records the top two direct
  // child nodes, where the time taken to mark the subtree rooted at each of the
  // child nodes is maximized, and returns the top child node.
  //
  // These values are used later in the rerooting process.
  int dfs(const vector<vector<int>>& tree, int u, int prev, vector<Top2>& dp) {
    Node top1;
    Node top2;
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      const int time = dfs(tree, v, u, dp) + getTime(v);
      if (time >= top1.time) {
        top2 = top1;
        top1 = Node(v, time);
      } else if (time > top2.time) {
        top2 = Node(v, time);
      }
    }
    dp[u] = Top2(top1, top2);
    return top1.time;
  }

  // Reroots the tree at node `u` and updates the answer array, where `maxTime`
  // is the longest path that doesn't go through `u`'s subtree.
  void reroot(const vector<vector<int>>& tree, int u, int prev, int maxTime,
              const vector<Top2>& dp, vector<int>& ans) {
    ans[u] = max(maxTime, dp[u].top1.time);
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      const int newMaxTime =
          getTime(u) + max(maxTime, dp[u].top1.node == v ? dp[u].top2.time
                                                         : dp[u].top1.time);
      reroot(tree, v, u, newMaxTime, dp, ans);
    }
  }
};
