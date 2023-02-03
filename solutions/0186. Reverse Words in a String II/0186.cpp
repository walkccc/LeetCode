class Solution {
 public:
  void reverseWords(vector<char>& s) {
    reverse(begin(s), end(s));  // Reverse the whole string
    reverseWords(s, s.size());  // Reverse each word
  }

 private:
  void reverseWords(vector<char>& s, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (i < j || i < n && s[i] == ' ')  // Skip spaces
        ++i;
      while (j < i || j < n && s[j] != ' ')  // Skip non spaces
        ++j;
      reverse(begin(s) + i, begin(s) + j);  // Reverse the word
    }
  }
};
