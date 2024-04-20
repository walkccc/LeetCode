class Solution {
 public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    vector<unordered_set<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0] - 1;
      const int v = edge[1] - 1;
      graph[u].insert(v);
      graph[v].insert(u);
    }

    const vector<int> oddNodes = getOddNodes(graph);
    if (oddNodes.empty())
      return true;
    if (oddNodes.size() == 2) {
      const int a = oddNodes[0];
      const int b = oddNodes[1];
      for (int i = 0; i < n; ++i)
        // Can connect i with a and i with b.
        if (!graph[i].count(a) && !graph[i].count(b))
          return true;
    }
    if (oddNodes.size() == 4) {
      const int a = oddNodes[0];
      const int b = oddNodes[1];
      const int c = oddNodes[2];
      const int d = oddNodes[3];
      return (!graph[a].count(b) && !graph[c].count(d)) ||
             (!graph[a].count(c) && !graph[b].count(d)) ||
             (!graph[a].count(d) && !graph[b].count(c));
    }
    return false;
  }

 private:
  vector<int> getOddNodes(const vector<unordered_set<int>>& graph) {
    vector<int> oddNodes;
    for (int i = 0; i < graph.size(); ++i)
      if (graph[i].size() & 1)
        oddNodes.push_back(i);
    return oddNodes;
  }
};
