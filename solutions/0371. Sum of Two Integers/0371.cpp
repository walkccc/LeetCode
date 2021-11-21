class Solution {
 public:
  int getSum(unsigned a, unsigned b) {
    while (b != 0) {                 // still have carry bits
      const unsigned carry = a & b;  // record carry bits
      a ^= b;                        // ^ works like + w/o handling carry bits
      b = carry << 1;
    }
    return a;
  }
};
