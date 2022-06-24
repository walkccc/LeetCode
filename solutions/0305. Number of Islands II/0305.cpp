class UF {
 public:
  vector<int> id;

  UF(int n) : id(n, -1) {}

  void union_(int u, int v) {
    id[u] = v;
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    const vector<int> dirs{0, 1, 0, -1, 0};
    vector<int> ans;
    vector<vector<bool>> seen(m, vector<bool>(n));
    UF uf(m * n);
    int count = 0;

    for (const auto& p : positions) {
      const int i = p[0];
      const int j = p[1];
      if (seen[i][j]) {
        ans.push_back(count);
        continue;
      }
      seen[i][j] = true;
      const int id = getId(i, j, n);
      uf.id[id] = id;
      ++count;
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        const int neighborId = getId(x, y, n);
        if (uf.id[neighborId] == -1)  // water
          continue;
        const int currentParent = uf.find(id);
        const int neighborParent = uf.find(neighborId);
        if (currentParent != neighborParent) {
          uf.union_(currentParent, neighborParent);
          --count;
        }
      }
      ans.push_back(count);
    }

    return ans;
  }

 private:
  int getId(int i, int j, int n) {
    return i * n + j;
  }
};
