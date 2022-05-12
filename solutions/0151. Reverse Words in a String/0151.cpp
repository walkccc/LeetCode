class Solution {
 public:
  string reverseWords(string s) {
    reverse(begin(s), end(s));          // reverse the whole string
    reverseWords(s, s.length());        // reverse each word
    return cleanSpaces(s, s.length());  // clean up spaces
  }

 private:
  void reverseWords(string& s, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (i < j || i < n && s[i] == ' ')  // skip spaces
        ++i;
      while (j < i || j < n && s[j] != ' ')  // skip non spaces
        ++j;
      reverse(begin(s) + i, begin(s) + j);  // reverse the word
    }
  }

  // trim leading, trailing, and middle spaces
  string cleanSpaces(string& s, int n) {
    int i = 0;
    int j = 0;

    while (j < n) {
      while (j < n && s[j] == ' ')  // skip spaces
        ++j;
      while (j < n && s[j] != ' ')  // keep non spaces
        s[i++] = s[j++];
      while (j < n && s[j] == ' ')  // skip spaces
        ++j;
      if (j < n)  // keep only one space
        s[i++] = ' ';
    }

    return s.substr(0, i);
  }
};
