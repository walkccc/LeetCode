class Solution {
 public:
  int appendCharacters(string s, string t) {
    int i = 0;  // t's index

    for (const char c : s)
      if (c == t[i])
        if (++i == t.length())
          return 0;

    return t.length() - i;
  }
};
