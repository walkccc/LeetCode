class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int area = 0;
    int x1 = INT_MAX;
    int y1 = INT_MAX;
    int x2 = INT_MIN;
    int y2 = INT_MIN;
    unordered_set<string> corners;

    for (const auto& r : rectangles) {
      area += (r[2] - r[0]) * (r[3] - r[1]);
      x1 = min(x1, r[0]);
      y1 = min(y1, r[1]);
      x2 = max(x2, r[2]);
      y2 = max(y2, r[3]);

      // four points of current rectangle
      const vector<string> points{to_string(r[0]) + " " + to_string(r[1]),
                                  to_string(r[0]) + " " + to_string(r[3]),
                                  to_string(r[2]) + " " + to_string(r[1]),
                                  to_string(r[2]) + " " + to_string(r[3])};
      for (const string& point : points)
        if (!corners.insert(point).second)
          corners.erase(point);
    }

    if (corners.size() != 4)
      return false;
    if (!corners.count(to_string(x1) + " " + to_string(y1)) ||
        !corners.count(to_string(x1) + " " + to_string(y2)) ||
        !corners.count(to_string(x2) + " " + to_string(y1)) ||
        !corners.count(to_string(x2) + " " + to_string(y2)))
      return false;

    return area == (x2 - x1) * (y2 - y1);
  }
};
