struct T {
  int sum;
  int count;
};

class Solution {
 public:
  int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
    vector<vector<int>> graph(nodes);

    for (int i = 1; i < parent.size(); ++i)
      graph[parent[i]].push_back(i);

    return dfs(graph, 0, value).count;
  }

 private:
  T dfs(const vector<vector<int>>& graph, int u, const vector<int>& value) {
    int sum = value[u];  // root value
    int count = 1;       // this root

    for (const int v : graph[u]) {
      const T t = dfs(graph, v, value);
      sum += t.sum;
      count += t.count;
    }

    if (sum == 0)     // delete this u
      return {0, 0};  // so its count = 0
    return {sum, count};
  }
};
