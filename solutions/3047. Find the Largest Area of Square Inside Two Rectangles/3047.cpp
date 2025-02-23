class Solution {
 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    int minSide = 0;

    for (int i = 0; i < bottomLeft.size(); ++i)
      for (int j = i + 1; j < bottomLeft.size(); ++j) {
        const int ax1 = bottomLeft[i][0];
        const int ay1 = bottomLeft[i][1];
        const int ax2 = topRight[i][0];
        const int ay2 = topRight[i][1];
        const int bx1 = bottomLeft[j][0];
        const int by1 = bottomLeft[j][1];
        const int bx2 = topRight[j][0];
        const int by2 = topRight[j][1];
        const int overlapX = min(ax2, bx2) - max(ax1, bx1);
        const int overlapY = min(ay2, by2) - max(ay1, by1);
        minSide = max(minSide, min(overlapX, overlapY));
      }

    return static_cast<long>(minSide) * minSide;
  }
};
