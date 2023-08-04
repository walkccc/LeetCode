class Solution {
 public:
  int getSum(unsigned a, unsigned b) {
    while (b) {                      // Still have carry bits
      const unsigned carry = a & b;  // Record carry bits
      a ^= b;                        // ^ works like + w/o handling carry bits
      b = carry << 1;
    }
    return a;
  }
};
