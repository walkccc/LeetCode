class Solution {
 public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2)
      return true;
    const string hashKey = s1 + '+' + s2;
    if (const auto it = memo.find(hashKey); it != memo.cend())
      return it->second;

    vector<int> count(128);

    for (int i = 0; i < s1.length(); ++i) {
      ++count[s1[i]];
      --count[s2[i]];
    }

    if (ranges::any_of(count, [](int c) { return c != 0; }))
      return memo[hashKey] = false;

    for (int i = 1; i < s1.length(); ++i) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i)))
        return memo[hashKey] = true;
      if (isScramble(s1.substr(0, i), s2.substr(s2.length() - i)) &&
          isScramble(s1.substr(i), s2.substr(0, s2.length() - i)))
        return memo[hashKey] = true;
    }

    return memo[hashKey] = false;
  }

 private:
  unordered_map<string, bool> memo;
};
