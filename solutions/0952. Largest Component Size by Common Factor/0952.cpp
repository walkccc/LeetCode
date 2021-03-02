class UF {
 public:
  UF(int n) : rank(n + 1), parent(n + 1) {
    iota(begin(parent), end(parent), 0);
  }

  void union_(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv)
      return;

    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pv] < rank[pu])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }
  }

  int find(int u) {
    while (u != parent[u]) {
      parent[u] = parent[parent[u]];
      u = parent[u];
    }

    return u;
  }

 private:
  vector<int> rank;
  vector<int> parent;
};

class Solution {
 public:
  int largestComponentSize(vector<int>& A) {
    const int n = *max_element(begin(A), end(A));

    int ans = 0;
    UF uf(n);
    unordered_map<int, int> count;

    for (int a : A)
      for (int num = 2; num <= sqrt(a); ++num)
        if (a % num == 0) {
          uf.union_(a, num);
          uf.union_(a, a / num);
        }

    for (int a : A)
      ans = max(ans, ++count[uf.find(a)]);

    return ans;
  }
};
