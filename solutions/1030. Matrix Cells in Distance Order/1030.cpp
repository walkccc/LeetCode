class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                        int cCenter) {
    const vector<int> dirs{0, 1, 0, -1, 0};
    vector<vector<int>> ans;
    vector<vector<int>> seen(rows, vector<int>(cols));
    queue<pair<int, int>> q{{{rCenter, cCenter}}};
    seen[rCenter][cCenter] = true;

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      ans.push_back({i, j});
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == rows || y < 0 || y == cols)
          continue;
        if (seen[x][y])
          continue;
        seen[x][y] = true;
        q.emplace(x, y);
      }
    }

    return ans;
  }
};
