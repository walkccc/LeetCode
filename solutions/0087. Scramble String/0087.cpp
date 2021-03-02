class Solution {
 public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2)
      return true;
    if (s1.length() != s2.length())
      return false;
    const string hashedKey = s1 + '+' + s2;
    if (memo.count(hashedKey))
      return memo[hashedKey];

    vector<int> count(128);

    for (int i = 0; i < s1.length(); ++i) {
      ++count[s1[i]];
      --count[s2[i]];
    }

    if (any_of(begin(count), end(count), [](int c) { return c != 0; }))
      return memo[hashedKey] = false;

    for (int i = 1; i < s1.length(); ++i) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i)))
        return memo[hashedKey] = true;
      if (isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) &&
          isScramble(s1.substr(i), s2.substr(0, s2.length() - i)))
        return memo[hashedKey] = true;
    }

    return memo[hashedKey] = false;
  }

 private:
  unordered_map<string, bool> memo;
};
