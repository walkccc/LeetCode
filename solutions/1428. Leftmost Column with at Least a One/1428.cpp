/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *  public:
 *   int get(int row, int col);
 *   vector<int> dimensions();
 * };
 */

class Solution {
 public:
  int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
    const vector<int> dimensions = binaryMatrix.dimensions();
    const int m = dimensions[0];
    const int n = dimensions[1];
    int ans = -1;
    int l = 0;
    int r = n - 1;

    while (l <= r) {
      const int mid = (l + r) / 2;
      if (existOne(binaryMatrix, m, mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }

 private:
  bool existOne(BinaryMatrix& binaryMatrix, int m, int col) {
    for (int i = 0; i < m; ++i)
      if (binaryMatrix.get(i, col) == 1)
        return true;
    return false;
  }
};
