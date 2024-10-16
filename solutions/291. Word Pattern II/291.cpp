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
      // See if we can match t with s[j..n).
      if (s.substr(j).find(t) == string::npos)
        return false;

      // If there's a match, continue to match the rest.
      return isMatch(pattern, i + 1, s, j + t.length(), std::move(charToString),
                     std::move(seen));
    }

    for (int k = j; k < s.length(); ++k) {
      const string& t = s.substr(j, k - j + 1);

      // This string is mapped by another character.
      if (seen.contains(t))
        continue;

      charToString[c] = t;
      seen.insert(t);

      if (isMatch(pattern, i + 1, s, k + 1, std::move(charToString),
                  std::move(seen)))
        return true;

      // Backtrack.
      charToString.erase(c);
      seen.erase(t);
    }

    return false;
  }
};
