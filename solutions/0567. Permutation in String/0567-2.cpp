class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    vector<int> count(128);
    int required = s1.length();

    for (const char c : s1)
      ++count[c];

    for (int r = 0; r < s2.length(); ++r) {
      if (--count[s2[r]] >= 0)
        --required;
      if (r >= s1.length())  // the window is oversized
        if (++count[s2[r - s1.length()]] > 0)
          ++required;
      if (required == 0)
        return true;
    }

    return false;
  }
};
