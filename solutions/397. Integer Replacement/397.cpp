class Solution {
 public:
  int integerReplacement(long n) {
    int ans = 0;

    for (; n > 1; ++ans)
      if ((n & 1) == 0)  // `n` ends in 0.
        n >>= 1;
      else if (n == 3 || ((n >> 1) & 1) == 0)  // `n` = 3 or ends in 0b01.
        --n;
      else  // `n` ends in 0b11.
        ++n;

    return ans;
  }
};
