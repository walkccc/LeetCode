class Solution {
 public:
  bool wordPatternMatch(string pattern, string s) {
    return isMatch(pattern, 0, s, 0, unordered_map<char, string>(),
                   unordered_set<string>());
  }

 private:
  bool isMatch(const string& pattern, int i, const string& s, int j,
               unordered_map<char, string>&& charToString,
               unordered_set<string>&& seen) {
    if (i == pattern.length() && j == s.length())
      return true;
    if (i == pattern.length() || j == s.length())
      return false;

    const char c = pattern[i];

    if (const auto it = charToString.find(c); it != charToString.cend()) {
      const string& t = it->second;
      // Check if we can match t w/ s[j:]
      if (s.substr(j).find(t) == string::npos)
        return false;

      // If can match, so continue match the rest
      return isMatch(pattern, i + 1, s, j + t.length(), move(charToString),
                     move(seen));
    }

    for (int k = j; k < s.length(); ++k) {
      const string& t = s.substr(j, k - j + 1);

      // This string is already mapped by other character
      if (seen.count(t))
        continue;

      charToString[c] = t;
      seen.insert(t);

      if (isMatch(pattern, i + 1, s, k + 1, move(charToString), move(seen)))
        return true;

      // Backtracking
      charToString.erase(c);
      seen.erase(t);
    }

    return false;
  }
};
