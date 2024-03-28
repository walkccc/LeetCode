class Solution {
 public:
  string longestNiceSubstring(string s) {
    if (s.length() < 2)
      return "";

    unordered_set<char> seen{s.begin(), s.end()};

    for (int i = 0; i < s.size(); ++i)
      // If both upper and lower case letters exists in the string, keep moving,
      // else take the erroneous character as a partition and check for its left
      // and right parts to be nice strings.
      if (!seen.count(toggleCase(s[i]))) {
        const string prefix = longestNiceSubstring(s.substr(0, i));
        const string suffix = longestNiceSubstring(s.substr(i + 1));
        return prefix.length() >= suffix.length() ? prefix : suffix;
      }

    return s;
  }

 private:
  char toggleCase(char c) {
    return islower(c) ? toupper(c) : tolower(c);
  }
};
