class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int ans = -1;
    int minDist = INT_MAX;

    for (int i = 0; i < points.size(); ++i) {
      const int dx = x - points[i][0];
      const int dy = y - points[i][1];
      if (dx == 0 || dy == 0) {
        const int dist = abs(dx + dy);
        if (dist < minDist) {
          minDist = dist;
          ans = i;
        }
      }
    }

    return ans;
  }
};
