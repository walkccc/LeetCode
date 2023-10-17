class Solution {
 public:
  string maximumOddBinaryNumber(string s) {
    const int zeros = count(s.begin(), s.end(), '0');
    const int ones = s.length() - zeros;
    return string(ones - 1, '1') + string(zeros, '0') + '1';
  }
};
