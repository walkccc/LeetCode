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
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    vector<bool> ans(queries.size());
    UnionFind uf(n);

    for (int i = 0; i < queries.size(); ++i)
      queries[i].push_back(i);

    ranges::sort(queries, ranges::less{},
                 [](const vector<int>& query) { return query[2]; });
    ranges::sort(edgeList, ranges::less{},
                 [](const vector<int>& edge) { return edge[2]; });

    int i = 0;  // i := edgeList's index
    for (const vector<int>& query : queries) {
      const int p = query[0];
      const int q = query[1];
      const int limit = query[2];
      // Union edges whose distances < limit.
      while (i < edgeList.size() && edgeList[i][2] < limit)
        uf.unionByRank(edgeList[i][0], edgeList[i++][1]);
      if (uf.find(p) == uf.find(q))
        ans[query.back()] = true;
    }

    return ans;
  }
};
