class Solution {
 public:
  string findValidPair(string s) {
    vector<int> count(10);

    for (const char c : s)
      ++count[c - '0'];

    for (int i = 0; i < s.length() - 1; ++i) {
      const int a = s[i] - '0';
      const int b = s[i + 1] - '0';
      if (a != b && count[a] == a && count[b] == b)
        return s.substr(i, 2);
    }

    return "";
  }
};
