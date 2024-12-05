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
  vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                              vector<vector<int>>& requests) {
    vector<bool> ans;
    UnionFind uf(n);

    for (const vector<int>& request : requests) {
      const int i = uf.find(request[0]);
      const int j = uf.find(request[1]);
      bool isValid = true;
      if (i != j)
        for (const vector<int>& restriction : restrictions) {
          const int x = uf.find(restriction[0]);
          const int y = uf.find(restriction[1]);
          if (i == x && j == y || i == y && j == x) {
            isValid = false;
            break;
          }
        }
      ans.push_back(isValid);
      if (isValid)
        uf.unionByRank(i, j);
    }

    return ans;
  }
};
