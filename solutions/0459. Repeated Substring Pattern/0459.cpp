class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    const string ss = s + s;
    return ss.substr(1, ss.length() - 2).find(s) != string::npos;
  }
};
