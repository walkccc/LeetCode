class UF {
 public:
  UF(int n) : id(n + 1) {
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
  int largestComponentSize(vector<int>& A) {
    const int n = *max_element(begin(A), end(A));
    int ans = 0;
    UF uf(n);
    unordered_map<int, int> count;

    for (const int a : A)
      for (int num = 2; num <= sqrt(a); ++num)
        if (a % num == 0) {
          uf.union_(a, num);
          uf.union_(a, a / num);
        }

    for (const int a : A)
      ans = max(ans, ++count[uf.find(a)]);

    return ans;
  }
};
