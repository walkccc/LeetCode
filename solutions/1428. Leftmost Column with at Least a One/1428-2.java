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
    int i = 0;
    int j = n - 1;

    while (i < m && j >= 0)
      if (binaryMatrix.get(i, j) == 1)
        ans = j--;
      else
        ++i;

    return ans;
  }
}
