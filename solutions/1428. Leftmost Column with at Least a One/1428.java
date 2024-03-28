/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface BinaryMatrix {
 *   public int get(int row, int col) {}
 *   public List<Integer> dimensions {}
 * };
 */

class Solution {
  public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
    final List<Integer> dimensions = binaryMatrix.dimensions();
    final int m = dimensions.get(0);
    final int n = dimensions.get(1);
    int ans = -1;
    int l = 0;
    int r = n - 1;

    while (l <= r) {
      final int mid = (l + r) / 2;
      if (existOne(binaryMatrix, m, mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }

  private boolean existOne(BinaryMatrix binaryMatrix, int m, int col) {
    for (int i = 0; i < m; ++i)
      if (binaryMatrix.get(i, col) == 1)
        return true;
    return false;
  }
}
