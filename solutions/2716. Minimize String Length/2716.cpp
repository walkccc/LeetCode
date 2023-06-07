class Solution {
 public:
  int minimizedStringLength(string s) {
    return unordered_set(begin(s), end(s)).size();
  }
};
