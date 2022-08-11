class UF {
 public:
  UF(int n) : id(n), size(n, 1) {
    iota(begin(id), end(id), 0);
  }

  void union_(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    id[i] = j;
    size[j] += size[i];
  }

  int getStableSize() {
    // bricks connected with 0 (top) are stable
    return size[find(0)];
  }

 private:
  vector<int> id;
  vector<int> size;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution {
 public:
  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    m = grid.size();
    n = grid[0].size();

    UF uf(m * n + 1);  // 0 := top (stable)

    // mark cells to hit as 2
    for (const auto& hit : hits) {
      const int i = hit[0];
      const int j = hit[1];
      if (grid[i][j] == 1)
        grid[i][j] = 2;
    }

    // union all 1s
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          unionNeighbors(grid, uf, i, j);

    vector<int> ans(hits.size());
    int stableSize = uf.getStableSize();

    for (int i = hits.size() - 1; i >= 0; --i) {
      const int x = hits[i][0];
      const int y = hits[i][1];
      if (grid[x][y] == 2) {  // cells marked from 1 to 2
        grid[x][y] = 1;       // unhit, restore back to 1
        unionNeighbors(grid, uf, x, y);
        const int newStableSize = uf.getStableSize();
        if (newStableSize > stableSize)
          ans[i] = newStableSize - stableSize - 1;  // 1 := the hit cell
        stableSize = newStableSize;
      }
    }

    return ans;
  }

 private:
  const vector<int> dirs{0, 1, 0, -1, 0};
  int m;
  int n;

  void unionNeighbors(const vector<vector<int>>& grid, UF& uf, int i, int j) {
    const int hashed = hash(i, j);

    for (int k = 0; k < 4; ++k) {
      const int x = i + dirs[k];
      const int y = j + dirs[k + 1];
      if (x < 0 || x == m || y < 0 || y == n)
        continue;
      if (grid[x][y] != 1)
        continue;
      uf.union_(hashed, hash(x, y));
    }

    if (i == 0)
      uf.union_(hashed, 0);
  }

  int hash(int i, int j) {
    return i * n + j + 1;
  }
};
