class Solution {
 public:
  int integerReplacement(long n) {
    int ans = 0;

    for (; n > 1; ++ans)
      if ((n & 1) == 0)  // ends w/ 0
        n >>= 1;
      else if (n == 3 || ((n >> 1) & 1) == 0)  // n = 3 or ends w/ 01
        --n;
      else  // ends w/ 11
        ++n;

    return ans;
  }
};
