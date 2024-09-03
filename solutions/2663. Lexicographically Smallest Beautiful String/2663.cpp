class Solution {
 public:
  string smallestBeautifulString(string s, int k) {
    for (int i = s.length() - 1; i >= 0; --i) {
      do {
        ++s[i];
      } while (containsPalindrome(s, i));
      if (s[i] < 'a' + k)
        // If s[i] is among the first k letters, then change the letters after
        // s[i] to the smallest ones that don't form any palindrome substring.
        return changeSuffix(s, i + 1);
    }

    return "";
  }

 private:
  // Returns true if s[0..i] contains any palindrome.
  bool containsPalindrome(const string& s, int i) {
    return (i > 0 && s[i] == s[i - 1]) || (i > 1 && s[i] == s[i - 2]);
  }

  // Returns a string, where replacing s[i..n) with the smallest possible
  // letters don't form any palindrome substring.
  string changeSuffix(string& s, int i) {
    for (int j = i; j < s.length(); ++j)
      for (s[j] = 'a'; containsPalindrome(s, j); ++s[j])
        ;
    return s;
  }
};
