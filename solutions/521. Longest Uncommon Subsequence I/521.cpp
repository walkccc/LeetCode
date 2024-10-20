class Solution {
 public:
  int findLUSlength(string a, string b) {
    return a == b ? -1 : max(a.length(), b.length());
  }
};
