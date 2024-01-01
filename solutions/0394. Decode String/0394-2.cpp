class Solution {
 public:
  string decodeString(string s) {
    string ans;

    while (i < s.length() && s[i] != ']')
      if (isdigit(s[i])) {
        int k = 0;
        while (i < s.length() && isdigit(s[i]))
          k = k * 10 + (s[i++] - '0');
        ++i;  // '['
        const string& decodedString = decodeString(s);
        ++i;  // ']'
        while (k-- > 0)
          ans += decodedString;
      } else {
        ans += s[i++];
      }

    return ans;
  }

 private:
  int i = 0;
};
