class Solution {
 public:
  string lastNonEmptyString(string s) {
    string ans;
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    const int maxFreq = ranges::max(count);

    for (int i = s.length() - 1; i >= 0; --i)
      if (count[s[i] - 'a']-- == maxFreq)
        ans += s[i];

    ranges::reverse(ans);
    return ans;
  }
};
