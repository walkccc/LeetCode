class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.empty())
      return "";

    // [start, end] indices of the longest palindrome in s
    pair<int, int> indices{0, 0};

    for (int i = 0; i < s.length(); ++i) {
      const auto [l1, r1] = extend(s, i, i);
      if (r1 - l1 > indices.second - indices.first)
        indices = {l1, r1};
      if (i + 1 < s.length() && s[i] == s[i + 1]) {
        const auto [l2, r2] = extend(s, i, i + 1);
        if (r2 - l2 > indices.second - indices.first)
          indices = {l2, r2};
      }
    }

    return s.substr(indices.first, indices.second - indices.first + 1);
  }

 private:
  // return [start, end] indices of the longest palindrome extended from s[i..j]
  pair<int, int> extend(const string& s, int i, int j) {
    for (; i >= 0 && j < s.length(); --i, ++j)
      if (s[i] != s[j])
        break;
    return {i + 1, j - 1};
  }
};
