class Solution {
 public:
  bool canMeasureWater(int x, int y, int z) {
    return z == 0 || (long)x + y >= z && z % __gcd(x, y) == 0;
  }
};
