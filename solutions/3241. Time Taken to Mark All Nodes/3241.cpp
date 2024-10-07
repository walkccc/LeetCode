struct T {
  int node = -1;
  int time = 0;
};

struct Top2 {
  T max1;
  T max2;
};

class Solution {
 public:
  vector<int> timeTaken(vector<vector<int>>& edges) {
    const int n = edges.size() + 1;
    vector<int> ans(n);
    vector<vector<int>> tree(n);
    // dp[i] := the top two nodes with maximum times to mark all nodes in the
    // subtree rooted at node i
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

  // Performs a DFS traversal of the tree, computing the maximum time to mark
  // all nodes in the subtree rooted at node u.
  //
  // This function calculates and stores the top two maximum times for each
  // node's subtree. These values are used later in the rerooting process.
  int dfs(const vector<vector<int>>& tree, int u, int prev, vector<Top2>& dp) {
    T max1;
    T max2;
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      const int time = dfs(tree, v, u, dp) + getTime(v);
      if (time >= max1.time) {
        max2 = max1;
        max1 = T(v, time);
      } else if (time > max2.time) {
        max2 = T(v, time);
      }
    }
    dp[u] = Top2(max1, max2);
    return max1.time;
  }

  // Reroots the tree at node `u` and updates the answer array, where `maxTime`
  // is the longest path that doesn't go through `u`'s subtree.
  void reroot(const vector<vector<int>>& tree, int u, int prev, int maxTime,
              const vector<Top2>& dp, vector<int>& ans) {
    ans[u] = max(maxTime, dp[u].max1.time);
    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      const int newMaxTime =
          getTime(u) + max(maxTime, dp[u].max1.node == v ? dp[u].max2.time
                                                         : dp[u].max1.time);
      reroot(tree, v, u, newMaxTime, dp, ans);
    }
  }
};
