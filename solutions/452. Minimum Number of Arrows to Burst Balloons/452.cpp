class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    ranges::sort(points,
                 [](const auto& a, const auto& b) { return a[1] < b[1]; });

    int ans = 1;
    int arrowX = points[0][1];

    for (int i = 1; i < points.size(); ++i)
      if (points[i][0] > arrowX) {
        arrowX = points[i][1];
        ++ans;
      }

    return ans;
  }
};
