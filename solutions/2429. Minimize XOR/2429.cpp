class Solution {
 public:
  int minimizeXor(unsigned num1, unsigned num2) {
    constexpr int kMaxBit = 30;
    int bits = popcount(num2);
    // Can turn off all the bits in `num1`.
    if (popcount(num1) == bits)
      return num1;

    int ans = 0;

    // Turn off the MSB if we have `bits` quota.
    for (int i = kMaxBit; i >= 0; --i)
      if (num1 >> i & 1) {
        ans |= 1 << i;
        if (--bits == 0)
          return ans;
      }

    // Turn on the LSB if we still have `bits`.
    for (int i = 0; i < kMaxBit; ++i)
      if ((num1 >> i & 1) == 0) {
        ans |= 1 << i;
        if (--bits == 0)
          return ans;
      }

    return ans;
  }
};
