class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double ans = 0;

    for (const auto& A : points)
      for (const auto& B : points)
        for (const auto& C : points)
          ans = max(ans, 0.5 * abs((B[0] - A[0]) * (C[1] - A[1]) -
                                   (C[0] - A[0]) * (B[1] - A[1])));

    return ans;
  }
};
