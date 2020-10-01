class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double ans = 0;

    for (vector<int>& A : points)
      for (vector<int>& B : points)
        for (vector<int>& C : points)
          ans = max(ans, 0.5 * abs((B[0] - A[0]) * (C[1] - A[1]) -
                                   (C[0] - A[0]) * (B[1] - A[1])));

    return ans;
  }
};