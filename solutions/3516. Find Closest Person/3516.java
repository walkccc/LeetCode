class Solution {
  public int findClosest(int x, int y, int z) {
    final int xz = Math.abs(x - z);
    final int yz = Math.abs(y - z);
    if (xz == yz)
      return 0;
    return xz < yz ? 1 : 2;
  }
}
