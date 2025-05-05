class Solution {
 public:
  int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                vector<vector<int>>& edges2) {
    const int diameter1 = getDiameter(edges1);
    const int diameter2 = getDiameter(edges2);
    const int combinedDiameter = (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1;
    return max({diameter1, diameter2, combinedDiameter});
  }

 private:
  int getDiameter(const vector<vector<int>>& edges) {
    const int n = edges.size() + 1;
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    int maxDiameter = 0;
    maxDepth(graph, 0, /*prev=*/-1, maxDiameter);
    return maxDiameter;
  }

  // Similar to 1522. Diameter of N-Ary Tree
  // Returns the maximum depth of the subtree rooted at u.
  int maxDepth(const vector<vector<int>>& graph, int u, int prev,
               int& maxDiameter) {
    int maxSubDepth1 = 0;
    int maxSubDepth2 = 0;
    for (const int v : graph[u]) {
      if (v == prev)
        continue;
      const int maxSubDepth = maxDepth(graph, v, u, maxDiameter);
      if (maxSubDepth > maxSubDepth1) {
        maxSubDepth2 = maxSubDepth1;
        maxSubDepth1 = maxSubDepth;
      } else if (maxSubDepth > maxSubDepth2) {
        maxSubDepth2 = maxSubDepth;
      }
    }
    maxDiameter = max(maxDiameter, maxSubDepth1 + maxSubDepth2);
    return 1 + maxSubDepth1;
  }
};
