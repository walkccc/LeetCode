class Solution {
 public:
  int minimizedStringLength(string s) {
    return unordered_set(s.begin(), s.end()).size();
  }
};
