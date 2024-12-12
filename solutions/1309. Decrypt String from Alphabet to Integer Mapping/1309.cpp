class Solution {
 public:
  string freqAlphabets(string s) {
    string ans;

    for (int i = 0; i < s.length();) {
      if (i + 2 < s.length() && s[i + 2] == '#') {
        ans += stoi(s.substr(i, 2)) + 'a' - 1;
        i += 3;
      } else {
        ans += (s[i] - '0') + 'a' - 1;
        i += 1;
      }
    }

    return ans;
  }
};
