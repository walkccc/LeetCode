class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length())
      return false;

    vector<int> count(128);

    for (const char c : s)
      ++count[c];

    for (const char c : t)
      if (--count[c] < 0)
        return false;

    return true;
  }
};
