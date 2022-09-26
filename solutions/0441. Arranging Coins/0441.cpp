class Solution {
 public:
  int arrangeCoins(long n) {
    return (-1 + sqrt(8 * n + 1)) / 2;
  }
};
