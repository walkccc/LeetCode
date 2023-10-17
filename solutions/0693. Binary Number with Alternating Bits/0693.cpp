class Solution {
 public:
  bool hasAlternatingBits(int n) {
    //            n = (010101)2
    //       n >> 2 = (000101)2
    // n ^ (n >> 2) = (010000)2 = a
    //        a - 1 = (001111)2
    //  a & (a - 1) = 0
    const int a = n ^ (n >> 2);
    return (a & (a - 1)) == 0;
  }
};
