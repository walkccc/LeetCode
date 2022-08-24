class UF {
 public:
  UF(int n) : id(n) {
    iota(begin(id), end(id), 0);
  }

  bool union_(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return false;
    id[i] = j;
    return true;
  }

 private:
  vector<int> id;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    vector<int> ids(edges.size() + 1);
    int nodeWithTwoParents = 0;

    for (const auto& e : edges) {
      const int v = e[1];
      if (++ids[v] == 2) {
        nodeWithTwoParents = v;
        break;
      }
    }

    // if there is no edge with two ids
    // we don't have to skip any edge
    if (!nodeWithTwoParents)
      return findRedundantDirectedConnection(edges, -1);

    for (int i = edges.size() - 1; i >= 0; --i)
      if (edges[i][1] == nodeWithTwoParents)
        // try to delete edges[i]
        if (findRedundantDirectedConnection(edges, i).empty())
          return edges[i];

    throw;
  }

  vector<int> findRedundantDirectedConnection(const vector<vector<int>>& edges,
                                              int skippedEdgeIndex) {
    UF uf(edges.size() + 1);

    for (int i = 0; i < edges.size(); ++i) {
      if (i == skippedEdgeIndex)
        continue;
      if (!uf.union_(edges[i][0], edges[i][1]))
        return edges[i];
    }

    return {};
  }
};
