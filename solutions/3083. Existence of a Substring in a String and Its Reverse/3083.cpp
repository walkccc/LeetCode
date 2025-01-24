class Solution {
 public:
  bool isSubstringPresent(string s) {
    const string reversed = {s.rbegin(), s.rend()};
    for (int i = 0; i + 2 <= s.length(); ++i)
      if (reversed.find(s.substr(i, 2)) != string::npos)
        return true;
    return false;
  }
};
