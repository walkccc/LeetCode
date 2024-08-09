class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    string ans;
    int length = 0;

    for (int i = s.length() - 1; i >= 0; --i) {
      if (s[i] == '-')
        continue;
      if (length > 0 && length % k == 0)
        ans += "-";
      ans += toupper(s[i]);
      ++length;
    }

    return {ans.rbegin(), ans.rend()};
  }
};
