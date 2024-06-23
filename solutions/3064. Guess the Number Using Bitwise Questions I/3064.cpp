/**
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
 public:
  int findNumber() {
    constexpr int kMaxBit = 30;
    int ans = 0;
    for (int i = 0; i <= kMaxBit; ++i)
      if (commonSetBits(1 << i) == 1)
        ans |= 1 << i;
    return ans;
  }
};
