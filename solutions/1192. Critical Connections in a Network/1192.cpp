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

  // the minRank that node can reach w/ forward edges
  int dfs(const vector<vector<int>>& graph, int node, int myRank,
          vector<int>& rank, vector<vector<int>>& ans) {
    if (rank[node] != NO_RANK)  // the rank is already been determined
      return rank[node];

    rank[node] = myRank;
    int minRank = myRank;

    for (const int child : graph[node]) {
      // visited || parent (that's why NO_RANK = -2 instead of -1)
      if (rank[node] == rank.size() || rank[child] == myRank - 1)
        continue;
      const int childRank = dfs(graph, child, myRank + 1, rank, ans);
      // path(node, child) is the only way for node go to child
      if (childRank == myRank + 1)
        ans.push_back({node, child});
      minRank = min(minRank, childRank);
    }

    rank[node] = rank.size();  // mark as visited

    return minRank;
  }
};
