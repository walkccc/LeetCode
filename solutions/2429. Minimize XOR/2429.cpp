class Solution {
 public:
  int minimizeXor(int num1, int num2) {
    constexpr int kMaxBit = 30;
    int bits = __builtin_popcount(num2);
    // Can turn off all the bits in the `num1`.
    if (__builtin_popcount(num1) == bits)
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
