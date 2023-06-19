class Solution {
 public:
  int integerReplacement(long n) {
    int ans = 0;

    for (; n > 1; ++ans)
      if ((n & 1) == 0)  // Ends w/ 0
        n >>= 1;
      else if (n == 3 || ((n >> 1) & 1) == 0)  // N = 3 or ends w/ 01
        --n;
      else  // Ends w/ 11
        ++n;

    return ans;
  }
};
