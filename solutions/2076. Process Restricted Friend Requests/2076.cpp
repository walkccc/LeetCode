class UF {
 public:
  UF(int n) : id(n) {
    iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    id[u] = v;
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
};

class Solution {
 public:
  vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                              vector<vector<int>>& requests) {
    vector<bool> ans;
    UF uf(n);

    for (const auto& request : requests) {
      const int i = uf.find(request[0]);
      const int j = uf.find(request[1]);
      bool isValid = true;
      if (i != j)
        for (const auto& restriction : restrictions) {
          const int x = uf.find(restriction[0]);
          const int y = uf.find(restriction[1]);
          if (i == x && j == y || i == y && j == x) {
            isValid = false;
            break;
          }
        }
      ans.push_back(isValid);
      if (isValid)
        uf.union_(i, j);
    }

    return ans;
  }
};
