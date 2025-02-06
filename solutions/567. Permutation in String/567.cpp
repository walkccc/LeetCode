class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    vector<int> count(26);
    int required = s1.length();

    for (const char c : s1)
      ++count[c - 'a'];

    for (int l = 0, r = 0; r < s2.length(); ++r) {
      if (--count[s2[r] - 'a'] >= 0)
        --required;
      while (required == 0) {
        if (r - l + 1 == s1.length())
          return true;
        if (++count[s2[l++] - 'a'] > 0)
          ++required;
      }
    }

    return false;
  }
};
