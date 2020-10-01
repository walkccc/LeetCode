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
      while (i < j || i < n && s[i] == ' ') ++i;  // skip spaces
      while (j < i || j < n && s[j] != ' ') ++j;  // skip non spaces
      reverse(begin(s) + i, begin(s) + j);        // reverse the word
    }
  }

  // trim leading, trailing, and middle spaces
  string cleanSpaces(string& s, int n) {
    int i = 0;
    int j = 0;

    while (j < n) {
      while (j < n && s[j] == ' ') ++j;              // skip spaces
      while (j < n && s[j] != ' ') s[i++] = s[j++];  // keep non spaces
      while (j < n && s[j] == ' ') ++j;              // skip spaces
      if (j < n) s[i++] = ' ';                       // keep only one space
    }

    return s.substr(0, i);
  }
};