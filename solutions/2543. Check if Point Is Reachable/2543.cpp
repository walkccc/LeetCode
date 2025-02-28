class Solution {
 public:
  bool isReachable(unsigned targetX, unsigned targetY) {
    return popcount(gcd(targetX, targetY)) == 1;
  }
};
