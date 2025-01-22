class Solution {
 public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>>& queries) {
    vector<int> ans;
    unordered_map<int, int> nodeToFarthestNode;

    for (int i = 0; i < n - 1; ++i)
      nodeToFarthestNode[i] = i + 1;

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      // If `u` exists in the map and `v` is farther than the current farthest
      // node for `u`, we need to update the map and remove intermediate nodes.
      if (nodeToFarthestNode.contains(u) && nodeToFarthestNode[u] < v) {
        int node = nodeToFarthestNode[u];
        while (node < v) {
          const int cache = node;
          node = nodeToFarthestNode[node];
          nodeToFarthestNode.erase(cache);
        }
        nodeToFarthestNode[u] = v;
      }
      ans.push_back(nodeToFarthestNode.size());
    }

    return ans;
  }
};
