class UF {
 public:
  UF(int n) : parent(n) {
    iota(begin(parent), end(parent), 0);
  }

  void union_(int pu, int pv) {
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
  vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                              vector<vector<int>>& requests) {
    vector<bool> ans;
    UF uf(n);

    for (const auto& request : requests) {
      const int pu = uf.find(request[0]);
      const int pv = uf.find(request[1]);
      bool isValid = true;
      if (pu != pv)
        for (const auto& restriction : restrictions) {
          const int px = uf.find(restriction[0]);
          const int py = uf.find(restriction[1]);
          if (pu == px && pv == py || pu == py && pv == px) {
            isValid = false;
            break;
          }
        }
      ans.push_back(isValid);
      if (isValid)
        uf.union_(pu, pv);
    }

    return ans;
  }
};
