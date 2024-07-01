class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

class Solution {
 public:
  int magnificentSets(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    UnionFind uf(n);
    unordered_map<int, int> rootToGroupSize;

    for (const vector<int>& edge : edges) {
      const int u = edge[0] - 1;
      const int v = edge[1] - 1;
      graph[u].push_back(v);
      graph[v].push_back(u);
      uf.unionByRank(u, v);
    }

    for (int i = 0; i < n; ++i) {
      const int newGroupSize = bfs(graph, i);
      if (newGroupSize == -1)
        return -1;
      const int root = uf.find(i);
      auto& groupSize = rootToGroupSize[root];
      groupSize = max(groupSize, newGroupSize);
    }

    int ans = 0;
    for (const auto& [_, groupSize] : rootToGroupSize)
      ans += groupSize;

    return ans;
  }

 private:
  int bfs(const vector<vector<int>>& graph, int u) {
    int step = 0;
    queue<int> q{{u}};
    unordered_map<int, int> nodeToStep{{u, 1}};

    while (!q.empty()) {
      ++step;
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        for (const int v : graph[u]) {
          if (!nodeToStep.count(v)) {
            q.push(v);
            nodeToStep[v] = step + 1;
          } else if (nodeToStep[v] == step) {
            // There is an odd number of edges in the cycle.
            return -1;
          }
        }
      }
    }

    return step;
  }
};
