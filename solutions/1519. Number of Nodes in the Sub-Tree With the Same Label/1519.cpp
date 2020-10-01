class Solution {
 public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> ans(n);
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    function<vector<int>(int node, int parent)> dfs = [&](int node,
                                                          int parent) {
      vector<int> count(26);  // count of letters down from this node

      for (const int child : graph[node])
        if (child != parent) {  // avoid duplicate visiting
          vector<int> subCount = dfs(child, node);
          for (int i = 0; i < 26; ++i)
            count[i] += subCount[i];
        }

      ans[node] = ++count[labels[node] - 'a'];  // the node itself
      return count;
    };

    dfs(0, -1);

    return ans;
  }
};
