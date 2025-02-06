class Solution {
 public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = image.size();
    const int n = image[0].size();
    vector<int> topLeft{x, y};
    vector<int> bottomRight{x, y};
    queue<pair<int, int>> q{{{x, y}}};
    image[x][y] = '2';  // Mark as visited.

    while (!q.empty()) {
      const auto [i, j] = q.front();
      q.pop();
      for (const auto& [dx, dy] : dirs) {
        const int r = i + dx;
        const int c = j + dy;
        if (r < 0 || r == m || c < 0 || c == n)
          continue;
        if (image[r][c] != '1')
          continue;
        topLeft[0] = min(topLeft[0], r);
        topLeft[1] = min(topLeft[1], c);
        bottomRight[0] = max(bottomRight[0], r);
        bottomRight[1] = max(bottomRight[1], c);
        q.emplace(r, c);
        image[r][c] = '2';
      }
    }

    const int width = bottomRight[1] - topLeft[1] + 1;
    const int height = bottomRight[0] - topLeft[0] + 1;
    return width * height;
  }
};
