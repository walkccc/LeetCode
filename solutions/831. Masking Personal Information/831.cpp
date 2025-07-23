class Solution {
 public:
  string maskPII(string s) {
    const int atIndex = s.find('@');
    if (atIndex != string::npos) {
      ranges::transform(s, s.begin(), ::tolower);
      return s.substr(0, 1) + "*****" + s.substr(atIndex - 1);
    }

    string ans;
    for (const char c : s)
      if (isdigit(c))
        ans += c;

    if (ans.length() == 10)
      return "***-***-" + ans.substr(ans.length() - 4);
    return '+' + string(ans.length() - 10, '*') + "-***-***-" +
           ans.substr(ans.length() - 4);
  }
};
