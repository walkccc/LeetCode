class Solution {
 public:
  int countLatticePoints(vector<vector<int>>& circles) {
    set<pair<int, int>> points;

    // dx := relative to x
    // dy := relative to y
    // So, dx^2 + dy^2 = r^2.
    for (const vector<int>& c : circles) {
      const int x = c[0];
      const int y = c[1];
      const int r = c[2];
      for (int dx = -r; dx <= r; ++dx) {
        const int yMax = sqrt(r * r - dx * dx);
        for (int dy = -yMax; dy <= yMax; ++dy)
          points.emplace(x + dx, y + dy);
      }
    }

    return points.size();
  }
};
