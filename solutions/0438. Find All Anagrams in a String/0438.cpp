class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    vector<int> count(128);
    int required = p.length();

    for (const char c : p)
      ++count[c];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (--count[s[r]] >= 0)
        --required;
      while (required == 0) {
        if (r - l + 1 == p.length())
          ans.push_back(l);
        if (++count[s[l++]] > 0)
          ++required;
      }
    }

    return ans;
  }
};
