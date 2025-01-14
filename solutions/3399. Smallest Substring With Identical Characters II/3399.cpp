class Solution {
 public:
  // Same as 3398. Smallest Substring With Identical Characters I
  int minLength(string s, int numOps) {
    int l = 1;
    int r = s.length();

    while (l < r) {
      const int m = (l + r) / 2;
      if (getMinOps(s, m) <= numOps)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  // Returns the minimum number of operations needed to make all groups of
  // identical characters of length k or less.
  int getMinOps(const string& s, int k) {
    if (k == 1) {
      size_t res = 0;
      for (int i = 0; i < s.length(); ++i)
        if (s[i] - '0' == i % 2)
          ++res;
      return min(res, s.length() - res);
    }

    int res = 0;
    int runningLen = 1;

    for (int i = 1; i < s.length(); ++i)
      if (s[i] == s[i - 1]) {
        ++runningLen;
      } else {
        res += runningLen / (k + 1);
        runningLen = 1;
      }

    return res + runningLen / (k + 1);
  }
};
