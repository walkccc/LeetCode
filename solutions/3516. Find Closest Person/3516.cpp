class Solution {
 public:
  int findClosest(int x, int y, int z) {
    const int xz = abs(x - z);
    const int yz = abs(y - z);
    if (xz == yz)
      return 0;
    return xz < yz ? 1 : 2;
  }
};
