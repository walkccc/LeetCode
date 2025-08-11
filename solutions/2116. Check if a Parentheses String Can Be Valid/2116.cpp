class Solution {
 public:
  bool canBeValid(string s, string locked) {
    if (s.length() % 2 == 1)
      return false;

    const bool leftToRightIsOkay = check(s, locked, true);
    ranges::reverse(s);
    ranges::reverse(locked);
    const bool rightToLeftIsOkay = check(s, locked, false);
    return leftToRightIsOkay && rightToLeftIsOkay;
  }

 private:
  bool check(const string& s, const string& locked, bool isForward) {
    int changeable = 0;
    int l = 0;
    int r = 0;

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      const char lock = locked[i];
      if (lock == '0')
        ++changeable;
      else if (c == '(')
        ++l;
      else  // c == ')'
        ++r;
      if (isForward && changeable + l - r < 0)
        return false;
      if (!isForward && changeable + r - l < 0)
        return false;
    }

    return true;
  }
};
