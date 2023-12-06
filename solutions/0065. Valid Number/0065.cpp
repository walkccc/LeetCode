class Solution {
 public:
  bool isNumber(string s) {
    trim(s);
    if (s.empty())
      return false;

    bool seenNum = false;
    bool seenDot = false;
    bool seenE = false;

    for (int i = 0; i < s.length(); ++i) {
      switch (s[i]) {
        case '.':
          if (seenDot || seenE)
            return false;
          seenDot = true;
          break;
        case 'e':
        case 'E':
          if (seenE || !seenNum)
            return false;
          seenE = true;
          seenNum = false;
          break;
        case '+':
        case '-':
          if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
            return false;
          seenNum = false;
          break;
        default:
          if (!isdigit(s[i]))
            return false;
          seenNum = true;
      }
    }

    return seenNum;
  }

 private:
  void trim(string& s) {
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
  }
};
