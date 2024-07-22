class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    int i = s.length() - 1;  // s' index
    int j = t.length() - 1;  // t's index

    while (true) {
      // Delete characters of s if needed.
      int backspace = 0;
      while (i >= 0 && (s[i] == '#' || backspace > 0)) {
        backspace += s[i] == '#' ? 1 : -1;
        --i;
      }
      // Delete characters of t if needed.
      backspace = 0;
      while (j >= 0 && (t[j] == '#' || backspace > 0)) {
        backspace += t[j] == '#' ? 1 : -1;
        --j;
      }
      if (i >= 0 && j >= 0 && s[i] == t[j]) {
        --i;
        --j;
      } else {
        break;
      }
    }

    return i == -1 && j == -1;
  }
};
