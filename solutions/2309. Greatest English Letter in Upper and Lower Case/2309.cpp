class Solution {
 public:
  string greatestLetter(string s) {
    vector<bool> seen(128);

    for (const char c : s)
      seen[c] = true;

    for (int i = 25; i >= 0; --i)
      if (seen['a' + i] && seen['A' + i])
        return string(1, 'A' + i);

    return "";
  }
};
