class Solution {
 public:
  int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
    int ans = 0;
    int prevX = -w - 1;
    vector<int> xs;

    for (const vector<int>& point : points) {
      const int x = point[0];
      xs.push_back(x);
    }

    ranges::sort(xs);

    for (const int x : xs)
      if (x > prevX + w) {
        ++ans;
        prevX = x;
      }

    return ans;
  }
};
