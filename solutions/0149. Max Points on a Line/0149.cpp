class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int ans = 0;

    for (int i = 0; i < points.size(); ++i) {
      unordered_map<pair<int, int>, int, pairHash> slopeCount;
      const vector<int> p1{points[i]};
      int samePoints = 1;
      int maxPoints = 0;  // maximum number of points with the same slope
      for (int j = i + 1; j < points.size(); ++j) {
        const vector<int> p2{points[j]};
        if (p1 == p2)
          ++samePoints;
        else
          maxPoints = max(maxPoints, ++slopeCount[getSlope(p1, p2)]);
      }
      ans = max(ans, samePoints + maxPoints);
    }

    return ans;
  }

 private:
  pair<int, int> getSlope(const vector<int>& p, const vector<int>& q) {
    const int dx = p[0] - q[0];
    const int dy = p[1] - q[1];
    if (dx == 0)
      return {0, p[0]};
    if (dy == 0)
      return {p[1], 0};
    const int d = __gcd(dx, dy);
    return {dx / d, dy / d};
  }

  struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};
