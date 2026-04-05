class Solution {
 public:
  int maxProduct(int n) {
    string s = to_string(n);
    ranges::sort(s);
    const int sz = s.length();
    return (s[sz - 1] - '0') * (s[sz - 2] - '0');
  }
};
