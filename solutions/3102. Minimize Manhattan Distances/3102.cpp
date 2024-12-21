class Solution {
 public:
  int minimumDistance(vector<vector<int>>& points) {
    const auto [i, j] = maxManhattanDistance(points, -1);
    const auto [xi, yi] = maxManhattanDistance(points, i);
    const auto [xj, yj] = maxManhattanDistance(points, j);
    return min(manhattan(points, xi, yi), manhattan(points, xj, yj));
  }

 private:
  // Returns the pair of indices a and b where points[a] and points[b] have the
  // maximum Manhattan distance and a != excludedIndex and b != excludedIndex.
  pair<int, int> maxManhattanDistance(const vector<vector<int>>& points,
                                      int excludedIndex) {
    int minSum = INT_MAX;
    int maxSum = INT_MIN;
    int minDiff = INT_MAX;
    int maxDiff = INT_MIN;
    int minSumIndex = -1;
    int maxSumIndex = -1;
    int minDiffIndex = -1;
    int maxDiffIndex = -1;

    for (int i = 0; i < points.size(); ++i) {
      if (i == excludedIndex)
        continue;
      const int x = points[i][0];
      const int y = points[i][1];
      const int sum = x + y;
      const int diff = x - y;
      if (sum < minSum)
        minSum = sum, minSumIndex = i;
      if (sum > maxSum)
        maxSum = sum, maxSumIndex = i;
      if (diff < minDiff)
        minDiff = diff, minDiffIndex = i;
      if (diff > maxDiff)
        maxDiff = diff, maxDiffIndex = i;
    }

    return maxSum - minSum >= maxDiff - minDiff
               ? pair<int, int>(minSumIndex, maxSumIndex)
               : pair<int, int>(minDiffIndex, maxDiffIndex);
  }

  int manhattan(const vector<vector<int>>& points, int i, int j) {
    return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
  }
};
