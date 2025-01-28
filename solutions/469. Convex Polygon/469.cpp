class Solution {
 public:
  bool isConvex(vector<vector<int>>& points) {
    const int n = points.size();
    long sign = 0;

    for (int i = 0; i < points.size(); ++i) {
      const int cross =
          getCross(points[i], points[(i + 1) % n], points[(i + 2) % n]);
      if (cross == 0)  // p, q, r are collinear.
        continue;
      if (sign == 0)  // Find the first cross that's not 0.
        sign = cross;
      else if (cross * sign < 0)
        return false;
    }

    return true;
  }

 private:
  // Returns pq x qr.
  int getCross(const vector<int>& p, const vector<int>& q,
               const vector<int>& r) {
    return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0]);
  }
};
