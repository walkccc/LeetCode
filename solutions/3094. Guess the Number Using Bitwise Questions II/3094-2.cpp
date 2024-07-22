/**
 * Definition of commonBits API.
 * int commonBits(int num);
 */

class Solution {
 public:
  int findNumber() {
    constexpr int kMaxBit = 30;
    int ans = 0;

    for (int i = 0; i <= kMaxBit; ++i)
      if (commonBits(1 << i) > commonBits(1 << i))
        ans |= 1 << i;

    return ans;
  }
};
