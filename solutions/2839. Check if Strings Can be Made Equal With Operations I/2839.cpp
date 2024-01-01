class Solution {
 public:
  bool canBeEqual(string s1, string s2) {
    for (const string& a : swappedStrings(s1))
      for (const string& b : swappedStrings(s2))
        if (a == b)
          return true;
    return false;
  }

 private:
  vector<string> swappedStrings(const string& s) {
    vector<char> chars(s.begin(), s.end());
    return {s, string({chars[2], chars[1], chars[0], chars[3]}),
            string({chars[0], chars[3], chars[2], chars[1]}),
            string({chars[2], chars[3], chars[0], chars[1]})};
  }
};
