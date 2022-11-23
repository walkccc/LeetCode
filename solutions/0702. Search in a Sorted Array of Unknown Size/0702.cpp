/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *  public:
 *   int get(int index);
 * };
 */

class Solution {
 public:
  int search(const ArrayReader& reader, int target) {
    int l = 0;
    int r = 1e4;

    while (l < r) {
      const int m = (l + r) / 2;
      if (reader.get(m) < target)
        l = m + 1;
      else
        r = m;
    }

    return reader.get(l) == target ? l : -1;
  }
};
