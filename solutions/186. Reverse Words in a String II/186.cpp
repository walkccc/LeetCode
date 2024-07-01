class Solution {
 public:
  void reverseWords(vector<char>& s) {
    reverse(s.begin(), s.end());  // Reverse the whole string.
    reverseWords(s, s.size());    // Reverse each word.
  }

 private:
  void reverseWords(vector<char>& s, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (i < j || i < n && s[i] == ' ')  // Skip the spaces.
        ++i;
      while (j < i || j < n && s[j] != ' ')  // Skip the spaces.
        ++j;
      reverse(s.begin() + i, s.begin() + j);  // Reverse the word.
    }
  }
};
