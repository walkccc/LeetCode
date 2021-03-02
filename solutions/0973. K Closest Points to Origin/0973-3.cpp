class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    quickSelect(points, 0, points.size() - 1, K);
    return {begin(points), begin(points) + K};
  };

 private:
  void quickSelect(vector<vector<int>>& points, int l, int r, int K) {
    const int randIndex = rand() % (r - l + 1) + l;
    swap(points[randIndex], points[r]);
    const vector<int> pivot = points[r];

    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (squareDist(points[i]) <= squareDist(pivot))
        swap(points[nextSwapped++], points[i]);
    swap(points[nextSwapped], points[r]);

    const int count = nextSwapped - l + 1;  // # of points <= pivot
    if (count == K)
      return;
    if (count > K)
      quickSelect(points, l, nextSwapped - 1, K);
    else
      quickSelect(points, nextSwapped + 1, r, K - count);
  }

  int squareDist(const vector<int>& p) {
    return p[0] * p[0] + p[1] * p[1];
  }
};
