class UF {
 public:
  UF(int n) : id(n) {
    iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    id[find(u)] = find(v);
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
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
    for (const auto& q : queries) {
      // union edges whose distances < limit (q[2])
      while (i < edgeList.size() && edgeList[i][2] < q[2])
        uf.union_(edgeList[i][0], edgeList[i++][1]);
      if (uf.find(q[0]) == uf.find(q[1]))
        ans[q.back()] = true;
    }

    return ans;
  }
};
