class Solution {
 public:
  int minimumLength(string s) {
    int i = 0;
    int j = s.length() - 1;

    while (i < j && s[i] == s[j]) {
      const char c = s[i];
      while (i <= j && s[i] == c)
        ++i;
      while (i <= j && s[j] == c)
        --j;
    }

    return j - i + 1;
  }
};
