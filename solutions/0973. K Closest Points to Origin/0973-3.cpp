class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    quickSelect(points, 0, points.size() - 1, K);
    return vector<vector<int>>(begin(points), begin(points) + K);
  };

 private:
  void quickSelect(vector<vector<int>>& points, int left, int right, int K) {
    // randomly choose the pivot
    const int randIndex = rand() % (right - left + 1) + left;
    swap(points[randIndex], points[right]);
    const vector<int> pivot = points[right];

    int l = left;  // next swapped index
    for (int i = left; i < right; ++i)
      if (squareDistance(points[i]) < squareDistance(pivot))
        swap(points[l++], points[i]);
    swap(points[l], points[right]);

    const int count = l - left + 1;  // # of points <= pivot
    if (count == K) return;
    if (count > K)
      quickSelect(points, left, l - 1, K);
    else
      quickSelect(points, l + 1, right, K - count);
  }

  int squareDistance(const vector<int>& p) {
    return p[0] * p[0] + p[1] * p[1];
  }
};