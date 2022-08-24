class Solution {
 public:
  int visiblePoints(vector<vector<int>>& points, int angle,
                    vector<int>& location) {
    const int posX = location[0];
    const int posY = location[1];
    int maxVisible = 0;
    int same = 0;
    vector<double> pointAngles;

    for (const auto& p : points) {
      const int x = p[0];
      const int y = p[1];
      if (x == posX && y == posY)
        ++same;
      else
        pointAngles.push_back(getAngle(y - posY, x - posX));
    }

    sort(begin(pointAngles), end(pointAngles));

    const int n = pointAngles.size();
    for (int i = 0; i < n; ++i)
      pointAngles.push_back(pointAngles[i] + 360);

    for (int l = 0, r = 0; r < pointAngles.size(); ++r) {
      while (pointAngles[r] - pointAngles[l] > angle)
        ++l;
      maxVisible = max(maxVisible, r - l + 1);
    }

    return maxVisible + same;
  }

 private:
  double getAngle(int dy, int dx) {
    return atan2(dy, dx) * 180 / M_PI;
  }
};
