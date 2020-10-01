class Solution {
 public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> ans;
    vector<vector<int>> graph(n);
    vector<int> ranks(n, NO_RANK);

    for (const vector<int>& conn : connections) {
      graph[conn[0]].push_back(conn[1]);
      graph[conn[1]].push_back(conn[0]);
    }

    // return the minRank that current node can (indirectly) reach
    function<int(int, int)> dfs = [&](int node, int myRank) {
      if (ranks[node] != NO_RANK) return ranks[node];

      ranks[node] = myRank;
      int minRank = myRank;

      for (const int neighbor : graph[node]) {
        // parent (that's why NO_RANK = -2 instead of -1) || visited
        if (ranks[neighbor] == myRank - 1 || ranks[neighbor] == n) continue;
        const int neighborRank = dfs(neighbor, myRank + 1);
        if (neighborRank == myRank + 1)    // path(node, neighbor) is the only way
          ans.push_back({node, neighbor}); // for node go to neighbor
        minRank = min(minRank, neighborRank);
      }

      ranks[node] = n;  // mark as visited
      return minRank;
    };

    dfs(0, 0);

    return ans;
  }

 private:
  const int NO_RANK = -2;
};