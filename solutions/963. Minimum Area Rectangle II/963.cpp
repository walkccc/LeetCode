class Solution {
 public:
  double minAreaFreeRect(vector<vector<int>>& points) {
    long ans = LONG_MAX;
    // For each A, B pair points, {hash(A, B): (ax, ay, bx, by)}.
    unordered_map<int, vector<tuple<int, int, int, int>>> centerToPoints;

    for (const vector<int>& A : points)
      for (const vector<int>& B : points) {
        const int center = hash(A, B);
        centerToPoints[center].emplace_back(A[0], A[1], B[0], B[1]);
      }

    // For all pair points "that share the same center".
    for (const auto& [_, points] : centerToPoints)
      for (const auto& [ax, ay, bx, by] : points)
        for (const auto& [cx, cy, dx, dy] : points)
          // AC is perpendicular to AD.
          // AC dot AD = (cx - ax, cy - ay) dot (dx - ax, dy - ay) == 0.
          if ((cx - ax) * (dx - ax) + (cy - ay) * (dy - ay) == 0) {
            const long squaredArea =
                dist(ax, ay, cx, cy) * dist(ax, ay, dx, dy);
            if (squaredArea > 0)
              ans = min(ans, squaredArea);
          }

    return ans == LONG_MAX ? 0 : sqrt(ans);
  }

 private:
  int hash(const vector<int>& p, const vector<int>& q) {
    return ((long)(p[0] + q[0]) << 16) + (p[1] + q[1]);
  }

  long dist(int px, int py, int qx, int qy) {
    return (px - qx) * (px - qx) + (py - qy) * (py - qy);
  }
};
