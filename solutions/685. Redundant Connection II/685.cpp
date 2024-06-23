class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  bool unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return false;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
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
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    vector<int> ids(edges.size() + 1);
    int nodeWithTwoParents = 0;

    for (const vector<int>& edge : edges) {
      const int v = edge[1];
      if (++ids[v] == 2) {
        nodeWithTwoParents = v;
        break;
      }
    }

    // If there is no edge with two ids, don't skip any edge.
    if (nodeWithTwoParents == 0)
      return findRedundantDirectedConnection(edges, -1);

    for (int i = edges.size() - 1; i >= 0; --i)
      if (edges[i][1] == nodeWithTwoParents)
        // Try to delete the edges[i].
        if (findRedundantDirectedConnection(edges, i).empty())
          return edges[i];

    throw;
  }

  vector<int> findRedundantDirectedConnection(const vector<vector<int>>& edges,
                                              int skippedEdgeIndex) {
    UnionFind uf(edges.size() + 1);

    for (int i = 0; i < edges.size(); ++i) {
      if (i == skippedEdgeIndex)
        continue;
      if (!uf.unionByRank(edges[i][0], edges[i][1]))
        return edges[i];
    }

    return {};
  }
};
