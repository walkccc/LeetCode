class Solution {
 public:
  vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
    vector<int> ans(n);
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    // rank[i] := the minimum node that node i can reach with forward edges
    // Initialize with NO_RANK = -2 to indicate not visited.
    vector<int> cycle;
    getRank(graph, 0, 0, vector<int>(n, NO_RANK), cycle);

    queue<int> q;
    vector<bool> seen(n);
    for (const int u : cycle) {
      q.push(u);
      seen[u] = true;
    }

    int dist = 0;
    while (!q.empty()) {
      ++dist;
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u]) {
          if (seen[v])
            continue;
          q.push(v);
          seen[v] = true;
          ans[v] = dist;
        }
      }
    }

    return ans;
  }

 private:
  static constexpr int NO_RANK = -2;

  // The minRank that u can reach with forward edges
  int getRank(const vector<vector<int>>& graph, int u, int currRank,
              vector<int>&& rank, vector<int>& cycle) {
    if (rank[u] != NO_RANK)  // The rank is already determined
      return rank[u];

    rank[u] = currRank;
    int minRank = currRank;

    for (const int v : graph[u]) {
      // Visited || parent (that's why NO_RANK = -2 instead of -1)
      if (rank[v] == rank.size() || rank[v] == currRank - 1)
        continue;
      const int nextRank = getRank(graph, v, currRank + 1, move(rank), cycle);
      // NextRank should > currRank if there's no cycle
      if (nextRank <= currRank)
        cycle.push_back(v);
      minRank = min(minRank, nextRank);
    }

    rank[u] = rank.size();  // Mark as visited.
    return minRank;
  }
};
