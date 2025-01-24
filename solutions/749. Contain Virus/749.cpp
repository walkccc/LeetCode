struct Region {
  // Given m = the number of rows and n = the number of columns, (x, y) will be
  // hashed as x * n + y.
  unordered_set<int> infected;
  unordered_set<int> noninfected;
  int wallsRequired = 0;
};

class Solution {
 public:
  int containVirus(vector<vector<int>>& isInfected) {
    const int m = isInfected.size();
    const int n = isInfected[0].size();
    int ans = 0;

    while (true) {
      vector<Region> regions;
      vector<vector<bool>> seen(m, vector<bool>(n));

      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (isInfected[i][j] == 1 && !seen[i][j]) {
            Region region;
            // Use DFS to find all the regions (1s).
            dfs(isInfected, i, j, region, seen);
            if (!region.noninfected.empty())
              regions.push_back(region);
          }

      if (regions.empty())
        break;  // No region causes further infection.

      // Regions that infect the most neighbors will be sorted to the back of
      // the array.
      ranges::sort(regions, ranges::less{}, [](const Region& region) {
        return region.noninfected.size();
      });

      // Build walls around the region that infects the most neighbors.
      Region mostInfectedRegion = regions.back();
      regions.pop_back();
      ans += mostInfectedRegion.wallsRequired;

      for (const int neighbor : mostInfectedRegion.infected) {
        const int i = neighbor / n;
        const int j = neighbor % n;
        // The isInfected is now contained and won't be infected anymore.
        isInfected[i][j] = 2;
      }

      // For remaining regions, infect their neighbors.
      for (const Region& region : regions)
        for (const int neighbor : region.noninfected) {
          const int i = neighbor / n;
          const int j = neighbor % n;
          isInfected[i][j] = 1;
        }
    }

    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& isInfected, int i, int j, Region& region,
           vector<vector<bool>>& seen) {
    if (i < 0 || i == isInfected.size() || j < 0 || j == isInfected[0].size())
      return;
    if (seen[i][j] || isInfected[i][j] == 2)
      return;
    if (isInfected[i][j] == 0) {
      region.noninfected.insert(i * isInfected[0].size() + j);
      ++region.wallsRequired;
      return;
    }

    // isInfected[i][j] == 1
    seen[i][j] = true;
    region.infected.insert(i * isInfected[0].size() + j);

    dfs(isInfected, i + 1, j, region, seen);
    dfs(isInfected, i - 1, j, region, seen);
    dfs(isInfected, i, j + 1, region, seen);
    dfs(isInfected, i, j - 1, region, seen);
  }
};
