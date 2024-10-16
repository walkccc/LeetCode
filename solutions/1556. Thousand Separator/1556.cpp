class Solution {
 public:
  string thousandSeparator(int n) {
    const string s = to_string(n);
    string ans;

    for (int i = 0; i < s.length(); ++i) {
      if (i > 0 && (s.length() - i) % 3 == 0)
        ans += '.';
      ans += s[i];
    }

    return ans;
  }
};
