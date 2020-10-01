class Solution {
 public:
  string maskPII(string S) {
    int atIndex = S.find('@');
    if (atIndex != string::npos) {
      transform(begin(S), end(S), begin(S), ::tolower);
      return S.substr(0, 1) + "*****" + S.substr(atIndex - 1);
    }

    string ans;
    for (char c : S)
      if (isdigit(c)) ans += c;

    if (ans.length() == 10) return "***-***-" + ans.substr(ans.length() - 4);
    return '+' + string(ans.length() - 10, '*') + "-***-***-" +
           ans.substr(ans.length() - 4);
  }
};