/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *   public int get(int index) {}
 * }
 */

class Solution {
  public int search(ArrayReader reader, int target) {
    int l = 0;
    int r = (int) 1e4;

    while (l < r) {
      final int m = (l + r) / 2;
      if (reader.get(m) < target)
        l = m + 1;
      else
        r = m;
    }

    return reader.get(l) == target ? l : -1;
  }
}
