class Solution {
 public:
  void reverseWords(vector<char>& s) {
    reverse(begin(s), end(s));  // reverse the whole string
    reverseWords(s, s.size());  // reverse each word
  }

 private:
  void reverseWords(vector<char>& s, int n) {
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
};
