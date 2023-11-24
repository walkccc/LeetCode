class Solution {
 public:
  string validIPAddress(string IP) {
    string digit;
    istringstream iss(IP);

    if (ranges::count(IP, '.') == 3) {
      for (int i = 0; i < 4; ++i)  // Make sure we have 4 parts
        if (!getline(iss, digit, '.') || !isIPv4(digit))
          return "Neither";
      return "IPv4";
    }

    if (ranges::count(IP, ':') == 7) {
      for (int i = 0; i < 8; ++i)  // Make sure we have 8 parts
        if (!getline(iss, digit, ':') || !isIPv6(digit))
          return "Neither";
      return "IPv6";
    }

    return "Neither";
  }

 private:
  static inline string validIPv6Chars = "0123456789abcdefABCDEF";

  bool isIPv4(const string& digit) {
    if (digit.empty() || digit.length() > 3)
      return false;
    if (digit.length() > 1 && digit[0] == '0')
      return false;

    for (const char c : digit)
      if (c < '0' || c > '9')
        return false;

    const int num = stoi(digit);
    return 0 <= num && num <= 255;
  }

  bool isIPv6(const string& digit) {
    if (digit.empty() || digit.length() > 4)
      return false;

    for (const char c : digit)
      if (validIPv6Chars.find(c) == string::npos)
        return false;

    return true;
  }
};
