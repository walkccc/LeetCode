class Solution {
 public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>>& connections) {
    vector<vector<int>> ans;
    vector<vector<int>> graph(n);
    // rank[i] := min node that node i can reach w/ forward edges
    // initialize to NO_RANK = -2 indicates not visited
    vector<int> rank(n, NO_RANK);

    for (const auto& conn : connections) {
      graph[conn[0]].push_back(conn[1]);
      graph[conn[1]].push_back(conn[0]);
    }

    dfs(graph, 0, 0, rank, ans);

    return ans;
  }

 private:
  const int NO_RANK = -2;

  // the minRank that u can reach w/ forward edges
  int dfs(const vector<vector<int>>& graph, int u, int myRank,
          vector<int>& rank, vector<vector<int>>& ans) {
    if (rank[u] != NO_RANK)  // the rank is already been determined
      return rank[u];

    rank[u] = myRank;
    int minRank = myRank;

    for (const int v : graph[u]) {
      // visited || parent (that's why NO_RANK = -2 instead of -1)
      if (rank[u] == rank.size() || rank[v] == myRank - 1)
        continue;
      const int vRank = dfs(graph, v, myRank + 1, rank, ans);
      // path(u, v) is the only way for u go to v
      if (vRank == myRank + 1)
        ans.push_back({u, v});
      minRank = min(minRank, vRank);
    }

    rank[u] = rank.size();  // mark as visited

    return minRank;
  }
};
