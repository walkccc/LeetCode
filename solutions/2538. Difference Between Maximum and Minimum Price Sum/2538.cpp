struct MaxNode {
  int node;
  long long maxSum;
  long long secondMaxSum;
};

class Solution {
 public:
  long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
    long long ans = 0;
    vector<vector<int>> graph(n);
    vector<int> maxSums(n);  // maxSums[i] := max sum of tree rooted at i

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    fillMaxSums(graph, 0, -1, price, maxSums);
    dfs(graph, 0, -1, price, maxSums, 0, ans);
    return ans;
  }

 private:
  long long fillMaxSums(const vector<vector<int>>& graph, int u, int prev,
                        const vector<int>& price, vector<int>& maxSums) {
    long long maxChildSum = 0;
    for (const int v : graph[u])
      if (v != prev)
        maxChildSum =
            max(maxChildSum, fillMaxSums(graph, v, u, price, maxSums));
    return maxSums[u] = maxChildSum + price[u];
  }

  void dfs(const vector<vector<int>>& graph, int u, int prev,
           const vector<int>& price, const vector<int>& maxSums,
           long long maxOther, long long& ans) {
    MaxNode maxNode = getMaxNode(graph, u, prev, maxSums);
    if (graph[u].size() == 1)
      ans = u == 0 ? maxNode.maxSum : max(ans, maxOther);

    for (const int v : graph[u])
      if (v != prev)
        dfs(graph, v, u, price, maxSums,
            max(maxOther,
                v == maxNode.node ? maxNode.secondMaxSum : maxNode.maxSum) +
                price[u],
            ans);
  }

  MaxNode getMaxNode(const vector<vector<int>>& graph, int u, int prev,
                     const vector<int>& maxSums) {
    int node = -1;
    long long maxSum = 0;
    long long secondMaxSum = 0;

    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      if (maxSums[v] > maxSum) {
        secondMaxSum = maxSum;
        maxSum = maxSums[v];
        node = v;
      } else if (maxSums[v] > secondMaxSum) {
        secondMaxSum = maxSums[v];
      }
    }

    return {node, maxSum, secondMaxSum};
  }
};
