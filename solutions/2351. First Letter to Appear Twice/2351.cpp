class Solution {
 public:
  char repeatedCharacter(string s) {
    vector<bool> seen(26);

    for (const char c : s) {
      if (seen[c - 'a'])
        return c;
      seen[c - 'a'] = true;
    }

    throw;
  }
};
