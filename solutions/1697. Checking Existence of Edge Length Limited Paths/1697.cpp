class UF {
 public:
  UF(int n) : parent(n) {
    iota(begin(parent), end(parent), 0);
  }

  void union_(int u, int v) {
    const int pu = find(u);
    const int pv = find(v);
    if (pu == pv)
      return;

    parent[pu] = pv;
  }

  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

 private:
  vector<int> parent;
};

class Solution {
 public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    vector<bool> ans(queries.size());
    UF uf(n);

    for (int i = 0; i < queries.size(); ++i)
      queries[i].push_back(i);

    sort(begin(queries), end(queries),
         [](const auto& a, const auto& b) { return a[2] < b[2]; });
    sort(begin(edgeList), end(edgeList),
         [](const auto& a, const auto& b) { return a[2] < b[2]; });

    int i = 0;  // i := edgeList's index
    for (const auto& query : queries) {
      // union edges whose distances < limit (query[2])
      while (i < edgeList.size() && edgeList[i][2] < query[2])
        uf.union_(edgeList[i][0], edgeList[i++][1]);
      if (uf.find(query[0]) == uf.find(query[1]))
        ans[query.back()] = true;
    }

    return ans;
  }
};
