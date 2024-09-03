class Solution {
 public:
  // Similar to 1736. Latest Time by Replacing Hidden Digits
  string findLatestTime(string s) {
    string ans = s;
    if (s[0] == '?')
      ans[0] = s[1] == '?' || s[1] < '2' ? '1' : '0';
    if (s[1] == '?')
      ans[1] = ans[0] == '1' ? '1' : '9';
    if (s[3] == '?')
      ans[3] = '5';
    if (s[4] == '?')
      ans[4] = '9';
    return ans;
  }
};
