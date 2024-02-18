class Solution {
 public:
  int secondHighest(string s) {
    int maxDigit = -1;
    int secondMaxDigit = -1;

    for (const char c : s)
      if (isdigit(c)) {
        const int digit = c - '0';
        if (digit > maxDigit) {
          secondMaxDigit = maxDigit;
          maxDigit = digit;
        } else if (maxDigit > digit && digit > secondMaxDigit) {
          secondMaxDigit = digit;
        }
      }

    return secondMaxDigit;
  }
};
