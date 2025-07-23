class Solution {
 public:
  bool hasAlternatingBits(int n) {
    //            n = 0b010101
    //       n >> 2 = 0b000101
    // n ^ (n >> 2) = 0b010000 = a
    //        a - 1 = 0b001111
    //  a & (a - 1) = 0
    const int a = n ^ (n >> 2);
    return (a & (a - 1)) == 0;
  }
};
