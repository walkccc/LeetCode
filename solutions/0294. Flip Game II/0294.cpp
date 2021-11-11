class Solution {
 public:
  bool canWin(string s) {
    if (memo.count(s))
      return memo[s];

    // if any of s.substr(i, 2) == "++" and
    // your friend can't win after changing s.substr(i, 2) to "--" (or "-"),
    // then you can win
    for (int i = 0; i + 1 < s.length(); ++i)
      if (s[i] == '+' && s[i + 1] == '+' &&
          !canWin(s.substr(0, i) + '-' + s.substr(i + 2)))
        return memo[s] = true;

    return memo[s] = false;
  }

 private:
  unordered_map<string, bool> memo;
};
