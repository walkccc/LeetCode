class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(begin(id), end(id), 0);
  }

  bool unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return false;
    if (rank[i] < rank[j]) {
      id[i] = id[j];
    } else if (rank[i] > rank[j]) {
      id[j] = id[i];
    } else {
      id[i] = id[j];
      ++rank[j];
    }
    return true;
  }

 private:
  vector<int> id;
  vector<int> rank;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf(edges.size() + 1);

    for (const vector<int>& edge : edges)
      if (!uf.unionByRank(edge[0], edge[1]))
        return edge;

    throw;
  }
};
