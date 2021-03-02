struct T {
  int i;
  int j;
  int height;  // grid[i][j]
};

class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    const int n = grid.size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    int ans = grid[0][0];
    auto compare = [&](const T& a, const T& b) { return a.height > b.height; };
    priority_queue<T, vector<T>, decltype(compare)> pq(compare);
    vector<vector<bool>> seen(n, vector<bool>(n));

    pq.push({0, 0, grid[0][0]});
    seen[0][0] = true;

    while (!pq.empty()) {
      const auto [i, j, height] = pq.top();
      pq.pop();
      ans = max(ans, height);
      if (i == n - 1 && j == n - 1)
        break;
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == n || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        pq.push({x, y, grid[x][y]});
        seen[x][y] = true;
      }
    }

    return ans;
  }
};
