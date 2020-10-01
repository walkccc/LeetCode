class Solution {
 public:
  int myAtoi(string& s) {
    trim(s);
    if (s.empty()) return 0;

    long ans = 0;
    const bool isNegative = s[0] == '-';

    if (s[0] == '+' || s[0] == '-') s = s.substr(1);

    for (const char c : s) {
      if (!isdigit(c)) break;
      ans = ans * 10 + (c - '0');
      if (isNegative && -ans <= INT_MIN) return INT_MIN;
      if (!isNegative && ans >= INT_MAX) return INT_MAX;
    }

    return isNegative ? -ans : ans;
  }

 private:
  void trim(string& s) {
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
  }
};