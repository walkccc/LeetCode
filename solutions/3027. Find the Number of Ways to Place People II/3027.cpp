class Solution {
 public:
  // Same as 3025. Find the Number of Ways to Place People I
  int numberOfPairs(vector<vector<int>>& points) {
    int ans = 0;

    ranges::sort(points, [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    for (int i = 0; i < points.size(); ++i) {
      int maxY = INT_MIN;
      for (int j = i + 1; j < points.size(); ++j)
        if (points[i][1] >= points[j][1] && points[j][1] > maxY) {
          ++ans;
          maxY = points[j][1];
        }
    }

    return ans;
  }
};
