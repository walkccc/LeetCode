class Solution {
 public:
  int numberOfSpecialChars(string word) {
    int ans = 0;
    vector<bool> lower(26);
    vector<bool> upper(26);

    for (const char c : word)
      if (islower(c))
        lower[c - 'a'] = !upper[c - 'a'];
      else
        upper[c - 'A'] = true;

    for (int i = 0; i < 26; ++i)
      if (lower[i] && upper[i])
        ++ans;

    return ans;
  }
};
