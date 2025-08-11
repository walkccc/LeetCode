class Solution {
 public:
  long long maxNumber(long long n) {
    // assume n = 0b00...11???
    //        x = 0b00...01111
    //  since y = 0b00...10000 is in [x, n]
    //    and x & y = 0
    const int i = 63 - __builtin_clzll(n);
    return (1L << i) - 1;
  }
};
