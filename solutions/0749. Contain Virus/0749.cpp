struct Region {
  // given m = # of rows and n = # of cols, (x, y) will be hashed as x * n + y
  unordered_set<int> infected;
  unordered_set<int> noninfected;  // noninfected neighbors
  int wallsRequired = 0;
};

class Solution {
 public:
  int containVirus(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    int ans = 0;

    function<void(int, int, Region&, vector<vector<bool>>&)> dfs =
        [&](int i, int j, Region& region, vector<vector<bool>>& seen) {
          if (i < 0 || i == m || j < 0 || j == n) return;
          if (seen[i][j] || grid[i][j] == 2) return;
          if (grid[i][j] == 0) {
            region.noninfected.insert(i * n + j);
            ++region.wallsRequired;
            return;
          }

          // grid[i][j] == 1
          seen[i][j] = true;
          region.infected.insert(i * n + j);
          dfs(i + 1, j, region, seen);
          dfs(i - 1, j, region, seen);
          dfs(i, j + 1, region, seen);
          dfs(i, j - 1, region, seen);
        };

    while (true) {
      vector<Region> regions;
      vector<vector<bool>> seen(m, vector<bool>(n));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 1 && !seen[i][j]) {
            Region region;
            dfs(i, j, region, seen);  // use DFS to find all regions (1s)
            if (!region.noninfected.empty())
              regions.push_back(region);
          }

      if (regions.empty()) break;  // no region causes further infection

      // region which infects most neighbors is in the back
      sort(begin(regions), end(regions), [](const auto& a, const auto& b) {
        return a.noninfected.size() < b.noninfected.size();
      });

      // build walls around the region which infects most neighbors
      Region region = regions.back();
      regions.pop_back();
      ans += region.wallsRequired;

      for (const int neighbor : region.infected) {
        const int i = neighbor / n;
        const int j = neighbor % n;
        grid[i][j] = 2;  // the grid is now contained and won't be infected anymore
      }

      // for remaining regions, expand (infect their neighbors)
      for (const Region& region : regions)
        for (const int neighbor : region.noninfected) {
          const int i = neighbor / n;
          const int j = neighbor % n;
          grid[i][j] = 1;
        }
    }

    return ans;
  }
};