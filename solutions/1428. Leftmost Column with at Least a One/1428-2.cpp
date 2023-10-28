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
    int i = 0;
    int j = n - 1;

    while (i < m && j >= 0)
      if (binaryMatrix.get(i, j) == 1)
        ans = j--;
      else
        ++i;

    return ans;
  }
};
