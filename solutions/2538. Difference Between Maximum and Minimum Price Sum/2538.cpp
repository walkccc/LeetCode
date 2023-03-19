class Solution {
 public:
  long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
    int ans = 0;
    vector<vector<int>> graph(n);
    vector<int> maxSums(n);  // maxSums[i] := max sum of path rooted at i.

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    // Precalculate `maxSums`.
    maxSum(graph, 0, /*prev=*/-1, maxSums, price);
    reroot(graph, 0, /*prev=*/-1, /*parentSum=*/0, maxSums, price, ans);
    return ans;
  }

 private:
  int maxSum(const vector<vector<int>>& graph, int u, int prev,
             vector<int>& maxSums, const vector<int>& price) {
    int maxChildSum = 0;
    for (const int v : graph[u])
      if (prev != v)
        maxChildSum = max(maxChildSum, maxSum(graph, v, u, maxSums, price));
    return maxSums[u] = price[u] + maxChildSum;
  }

  void reroot(const vector<vector<int>>& graph, int u, int prev, int parentSum,
              const vector<int>& maxSums, const vector<int>& price, int& ans) {
    // Get top two subtree sums and top one node index.
    int maxSubtreeSum1 = 0;
    int maxSubtreeSum2 = 0;
    int maxNode = -1;
    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      if (maxSums[v] > maxSubtreeSum1) {
        maxSubtreeSum2 = maxSubtreeSum1;
        maxSubtreeSum1 = maxSums[v];
        maxNode = v;
      } else if (maxSums[v] > maxSubtreeSum2) {
        maxSubtreeSum2 = maxSums[v];
      }
    }

    if (graph[u].size() == 1)
      ans = max({ans, parentSum, maxSubtreeSum1});

    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      const int nextParentSum =
          (v == maxNode ? price[u] + max(parentSum, maxSubtreeSum2)
                        : price[u] + max(parentSum, maxSubtreeSum1));
      reroot(graph, v, u, nextParentSum, maxSums, price, ans);
    }
  }
};
