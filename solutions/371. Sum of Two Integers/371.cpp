class Solution {
 public:
  int getSum(unsigned a, unsigned b) {
    while (b > 0) {                  // Still have carry bits.
      const unsigned carry = a & b;  // Record the carry bits.
      a ^= b;  // ^ works like + without handling carry bits.
      b = carry << 1;
    }
    return a;
  }
};
