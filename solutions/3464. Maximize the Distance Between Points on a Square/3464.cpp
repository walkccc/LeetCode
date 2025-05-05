struct Sequence {
  int startX;
  int startY;
  int endX;
  int endY;
  int length;
};

class Solution {
 public:
  int maxDistance(int side, vector<vector<int>>& points, int k) {
    const vector<pair<int, int>> ordered = getOrderedPoints(side, points);
    int l = 0;
    int r = side;

    while (l < r) {
      const int m = (l + r + 1) / 2;
      if (isValidDistance(ordered, k, m))
        l = m;
      else
        r = m - 1;
    }

    return l;
  }

 private:
  // Returns true if we can select `k` points such that the minimum Manhattan
  // distance between any two consecutive chosen points is at least `m`.
  bool isValidDistance(const vector<pair<int, int>>& ordered, int k, int d) {
    deque<Sequence> dq{{ordered[0].first, ordered[0].second, ordered[0].first,
                        ordered[0].second, 1}};
    int maxLength = 1;

    for (int i = 1; i < ordered.size(); ++i) {
      const auto& [x, y] = ordered[i];
      int startX = x;
      int startY = y;
      int length = 1;
      while (!dq.empty() &&
             (abs(x - dq.front().endX) + abs(y - dq.front().endY) >= d)) {
        if (abs(x - dq.front().startX) + abs(y - dq.front().startY) >= d &&
            dq.front().length + 1 >= length) {
          startX = dq.front().startX;
          startY = dq.front().startY;
          length = dq.front().length + 1;
          maxLength = max(maxLength, length);
        }
        dq.pop_front();
      }
      dq.emplace_back(startX, startY, x, y, length);
    }

    return maxLength >= k;
  }

  // Returns the ordered points on the perimeter of a square of side length
  // `side`, starting from left, top, right, and bottom boundaries.
  vector<pair<int, int>> getOrderedPoints(int side,
                                          vector<vector<int>>& points) {
    vector<pair<int, int>> left;
    vector<pair<int, int>> top;
    vector<pair<int, int>> right;
    vector<pair<int, int>> bottom;

    for (const vector<int>& point : points) {
      const int x = point[0];
      const int y = point[1];
      if (x == 0 && y > 0)
        left.emplace_back(x, y);
      else if (x > 0 && y == side)
        top.emplace_back(x, y);
      else if (x == side && y < side)
        right.emplace_back(x, y);
      else
        bottom.emplace_back(x, y);
    }

    ranges::sort(left);
    ranges::sort(top);
    ranges::sort(right, greater<>());
    ranges::sort(bottom, greater<>());
    left.insert(left.end(), top.begin(), top.end());
    left.insert(left.end(), right.begin(), right.end());
    left.insert(left.end(), bottom.begin(), bottom.end());
    return left;
  }
};
