/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *   public int get(int index) {}
 *   public int length() {}
 * }
 */

class Solution {
  public int findInMountainArray(int target, MountainArray mountainArr) {
    final int n = mountainArr.length();
    final int peakIndex = peakIndexInMountainArray(mountainArr, 0, n - 1);

    final int leftIndex = searchLeft(mountainArr, target, 0, peakIndex);
    if (mountainArr.get(leftIndex) == target)
      return leftIndex;

    final int rightIndex = searchRight(mountainArr, target, peakIndex + 1, n - 1);
    if (mountainArr.get(rightIndex) == target)
      return rightIndex;

    return -1;
  }

  // 852. Peak Index in a Mountain Array
  private int peakIndexInMountainArray(MountainArray A, int l, int r) {
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) < A.get(m + 1))
        l = m + 1;
      else
        r = m;
    }
    return l;
  }

  private int searchLeft(MountainArray A, int target, int l, int r) {
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) < target)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }

  private int searchRight(MountainArray A, int target, int l, int r) {
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) > target)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
}
