class Solution {
 public:
  int findKthNumber(long n, int k) {
    auto getGap = [&n](long a, long b) {
      long gap = 0;
      while (a <= n) {
        gap += min(n + 1, b) - a;
        a *= 10;
        b *= 10;
      }
      return gap;
    };

    long currNum = 1;

    for (int i = 1; i < k;) {
      long gap = getGap(currNum, currNum + 1);
      if (i + gap <= k) {
        i += gap;
        ++currNum;
      } else {
        ++i;
        currNum *= 10;
      }
    }

    return currNum;
  }
};