class Solution {
 public:
  string maskPII(string S) {
    const int atIndex = S.find('@');
    if (atIndex != string::npos) {
      transform(begin(S), end(S), begin(S), ::tolower);
      return S.substr(0, 1) + "*****" + S.substr(atIndex - 1);
    }

    string s;
    for (const char c : S)
      if (isdigit(c))
        s += c;

    if (s.length() == 10)
      return "***-***-" + s.substr(s.length() - 4);
    return '+' + string(s.length() - 10, '*') + "-***-***-" +
           s.substr(s.length() - 4);
  }
};
