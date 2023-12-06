class UnionFind {
 public:
  void union_(int u, int v) {
    if (!id.count(u))
      id[u] = u;
    if (!id.count(v))
      id[v] = v;
    const int i = find(u);
    const int j = find(v);
    if (i != j)
      id[i] = j;
  }

  unordered_map<int, vector<int>> getGroupIdToValues() {
    unordered_map<int, vector<int>> groupIdToValues;
    for (const auto& [u, _] : id)
      groupIdToValues[find(u)].push_back(u);
    return groupIdToValues;
  }

 private:
  unordered_map<int, int> id;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    // {val: [(i, j)]}
    map<int, vector<pair<int, int>>> valToGrids;
    // rank[i] := the maximum rank of the row or column so far
    vector<int> maxRankSoFar(m + n);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        valToGrids[matrix[i][j]].emplace_back(i, j);

    for (const auto& [val, grids] : valToGrids) {
      UnionFind uf;
      for (const auto& [i, j] : grids)
        // Union i-th row with j-th col.
        uf.union_(i, j + m);
      for (const auto& [groupId, values] : uf.getGroupIdToValues()) {
        // Get the maximum rank of all the included rows and columns.
        int maxRank = 0;
        for (const int i : values)
          maxRank = max(maxRank, maxRankSoFar[i]);
        // Update all the rows and columns to maxRank + 1.
        for (const int i : values)
          maxRankSoFar[i] = maxRank + 1;
      }
      for (const auto& [i, j] : grids)
        ans[i][j] = maxRankSoFar[i];
    }

    return ans;
  }
};
