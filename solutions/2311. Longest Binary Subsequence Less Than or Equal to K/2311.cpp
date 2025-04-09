class Solution {
 public:
  int longestSubsequence(string s, int k) {
    int oneCount = 0;
    int num = 0;
    int pow = 1;

    // Take as many 1s as possible from the right.
    for (int i = s.length() - 1; i >= 0 && num + pow <= k; --i) {
      if (s[i] == '1') {
        ++oneCount;
        num += pow;
      }
      pow *= 2;
    }

    return ranges::count(s, '0') + oneCount;
  }
};
