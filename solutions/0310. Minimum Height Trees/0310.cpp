class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1 || edges.empty())
      return {0};

    vector<int> ans;
    unordered_map<int, unordered_set<int>> graph;

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      graph[u].insert(v);
      graph[v].insert(u);
    }

    for (const auto& [label, children] : graph)
      if (children.size() == 1)
        ans.push_back(label);

    while (n > 2) {
      n -= ans.size();
      vector<int> nextLeaves;
      for (const int leaf : ans) {
        const int u = *begin(graph[leaf]);
        graph[u].erase(leaf);
        if (graph[u].size() == 1)
          nextLeaves.push_back(u);
      }
      ans = nextLeaves;
    }

    return ans;
  }
};
