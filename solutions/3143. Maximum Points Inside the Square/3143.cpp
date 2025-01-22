class Solution {
 public:
  int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
    int secondMinSize = INT_MAX;
    vector<int> minSizes(26, INT_MAX);

    for (int i = 0; i < points.size(); ++i) {
      const int x = points[i][0];
      const int y = points[i][1];
      const int sz = max(abs(x), abs(y));
      const int j = s[i] - 'a';
      if (minSizes[j] == INT_MAX) {
        minSizes[j] = sz;
      } else if (sz < minSizes[j]) {
        // This is because minSizes[j] is about to be replaced by a smaller
        // value, so it becomes a candidate for the second minimum size.
        secondMinSize = min(secondMinSize, minSizes[j]);
        minSizes[j] = sz;
      } else {
        // `sz` is not smaller than the current minimum size, but it could be
        // smaller than the current second minimum size.
        secondMinSize = min(secondMinSize, sz);
      }
    }

    return ranges::count_if(minSizes,
                            [&](int sz) { return sz < secondMinSize; });
  }
};
