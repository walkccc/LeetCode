class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    quickSelect(points, 0, points.size() - 1, k);
    return {points.begin(), points.begin() + k};
  };

 private:
  void quickSelect(vector<vector<int>>& points, int l, int r, int k) {
    const vector<int> pivot = points[r];

    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (squareDist(points[i]) <= squareDist(pivot))
        swap(points[nextSwapped++], points[i]);
    swap(points[nextSwapped], points[r]);

    const int count = nextSwapped - l + 1;  // the number of points <= pivot
    if (count == k)
      return;
    if (count > k)
      quickSelect(points, l, nextSwapped - 1, k);
    else
      quickSelect(points, nextSwapped + 1, r, k - count);
  }

  int squareDist(const vector<int>& p) {
    return p[0] * p[0] + p[1] * p[1];
  }
};
