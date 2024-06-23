class Solution {
 public:
  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    constexpr int kMax = 50;
    const int n = towers.size();
    vector<int> ans(2);
    int maxQuality = 0;

    for (int i = 0; i <= kMax; ++i)
      for (int j = 0; j <= kMax; ++j) {
        int qualitySum = 0;
        for (const vector<int>& tower : towers) {
          const double d = dist(tower, i, j);
          if (d <= radius) {
            const int q = tower[2];
            qualitySum += static_cast<int>(q / (1 + d));
          }
        }
        if (qualitySum > maxQuality) {
          maxQuality = qualitySum;
          ans = {i, j};
        }
      }

    return ans;
  }

 private:
  // Returns the distance between the tower and the coordinate.
  double dist(const vector<int>& tower, int i, int j) {
    return sqrt(pow(tower[0] - i, 2) + pow(tower[1] - j, 2));
  }
};
