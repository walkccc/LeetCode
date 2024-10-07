class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> count(128);
    int required = t.length();
    int bestLeft = -1;
    int minLength = s.length() + 1;

    for (const char c : t)
      ++count[c];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (--count[s[r]] >= 0)
        --required;
      while (required == 0) {
        if (r - l + 1 < minLength) {
          bestLeft = l;
          minLength = r - l + 1;
        }
        if (++count[s[l++]] > 0)
          ++required;
      }
    }

    return bestLeft == -1 ? "" : s.substr(bestLeft, minLength);
  }
};
