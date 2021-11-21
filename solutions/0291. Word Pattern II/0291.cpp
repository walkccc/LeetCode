class Solution {
 public:
  bool wordPatternMatch(string pattern, string s) {
    unordered_map<char, string> charToString;
    unordered_set<string> seen;
    return isMatch(pattern, 0, s, 0, charToString, seen);
  }

 private:
  bool isMatch(const string& pattern, int i, const string& s, int j,
               unordered_map<char, string>& charToString,
               unordered_set<string>& seen) {
    if (i == pattern.length() && j == s.length())
      return true;
    if (i == pattern.length() || j == s.length())
      return false;

    const char c = pattern[i];

    if (charToString.count(c)) {
      const string& t = charToString[c];
      // check if we can match t w/ s[j..j + t.length())
      if (s.substr(j).find(t) != 0)
        return false;

      // if can match, so continue match the rest
      return isMatch(pattern, i + 1, s, j + t.length(), charToString, seen);
    }

    for (int k = j; k < s.length(); ++k) {
      const string& t = s.substr(j, k - j + 1);

      // this string is already mapped by other character
      if (seen.count(t))
        continue;

      charToString[c] = t;
      seen.insert(t);

      if (isMatch(pattern, i + 1, s, k + 1, charToString, seen))
        return true;

      // backtracking
      charToString.erase(c);
      seen.erase(t);
    }

    return false;
  }
};
