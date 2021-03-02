class Solution {
 public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> ans(n);
    vector<vector<int>> graph(n);

    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    dfs(graph, 0, -1, labels, ans);

    return ans;
  }

 private:
  vector<int> dfs(const vector<vector<int>>& graph, int node, int parent,
                  const string& labels, vector<int>& ans) {
    vector<int> count(26);  // count of letters down from this node

    for (const int child : graph[node]) {
      if (child == parent)
        continue;
      vector<int> childCount = dfs(graph, child, node, labels, ans);
      for (int i = 0; i < 26; ++i)
        count[i] += childCount[i];
    }

    ans[node] = ++count[labels[node] - 'a'];  // the node itself
    return count;
  }
};
