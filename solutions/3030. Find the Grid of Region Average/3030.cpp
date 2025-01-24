class Solution {
 public:
  vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
    const int m = image.size();
    const int n = image[0].size();
    vector<vector<int>> sums(m, vector<int>(n));
    vector<vector<int>> counts(m, vector<int>(n));

    for (int i = 0; i < m - 2; ++i)
      for (int j = 0; j < n - 2; ++j)
        if (isRegion(image, i, j, threshold)) {
          const int subgridSum = getSubgridSum(image, i, j);
          for (int x = i; x < i + 3; ++x)
            for (int y = j; y < j + 3; ++y) {
              sums[x][y] += subgridSum / 9;
              counts[x][y] += 1;
            }
        }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (counts[i][j] > 0)
          image[i][j] = sums[i][j] / counts[i][j];

    return image;
  }

 private:
  // Returns true if image[i..i + 2][j..j + 2] is a region.
  bool isRegion(const vector<vector<int>>& image, int i, int j, int threshold) {
    for (int x = i; x < i + 3; ++x)
      for (int y = j; y < j + 3; ++y) {
        if (x > i && abs(image[x][y] - image[x - 1][y]) > threshold)
          return false;
        if (y > j && abs(image[x][y] - image[x][y - 1]) > threshold)
          return false;
      }
    return true;
  }

  // Returns the sum of image[i..i + 2][j..j + 2].
  int getSubgridSum(const vector<vector<int>>& image, int i, int j) {
    int subgridSum = 0;
    for (int x = i; x < i + 3; ++x)
      for (int y = j; y < j + 3; ++y)
        subgridSum += image[x][y];
    return subgridSum;
  }
};
