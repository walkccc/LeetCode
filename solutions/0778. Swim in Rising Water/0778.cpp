struct Item {
  int i;
  int j;
};

class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    const int n = grid.size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    int ans = grid[0][0];
    auto compare = [&](const Item& a, const Item& b) {
      return grid[a.i][a.j] > grid[b.i][b.j];
    };
    priority_queue<Item, vector<Item>, decltype(compare)> pq(compare);
    vector<vector<bool>> seen(n, vector<bool>(n));

    pq.push({0, 0});
    seen[0][0] = true;

    while (!pq.empty()) {
      const auto [i, j] = pq.top(); pq.pop();
      ans = max(ans, grid[i][j]);
      if (i == n - 1 && j == n - 1) break;
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == n || y < 0 || y == n) continue;
        if (seen[x][y]) continue;
        pq.push({x, y});
        seen[x][y] = true;
      }
    }

    return ans;
  }
};