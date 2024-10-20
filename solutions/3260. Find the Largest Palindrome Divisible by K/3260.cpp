class Solution {
 public:
  string largestPalindrome(int n, int k) {
    switch (k) {
      case 1:
        return string(n, '9');
      case 2:
        return n <= 2 ? string(n, '8') : "8" + string(n - 2, '9') + "8";
      case 3:
      case 9:
        return string(n, '9');
      case 4:
        return n <= 4 ? string(n, '8') : "88" + string(n - 4, '9') + "88";
      case 5:
        return n <= 2 ? string(n, '5') : "5" + string(n - 2, '9') + "5";
      case 6:
        if (n <= 2) {
          return string(n, '6');
        } else if (n % 2 == 1) {
          const int l = n / 2 - 1;
          return "8" + string(l, '9') + "8" + string(l, '9') + "8";
        } else {
          const int l = n / 2 - 2;
          return "8" + string(l, '9') + "77" + string(l, '9') + "8";
        }
      case 8:
        return n <= 6 ? string(n, '8') : "888" + string(n - 6, '9') + "888";
      default:
        const string middle[] = {"",          "7",          "77",
                                 "959",       "9779",       "99799",
                                 "999999",    "9994999",    "99944999",
                                 "999969999", "9999449999", "99999499999"};
        const int q = n / 12;
        const int r = n % 12;
        return string(q * 6, '9') + middle[r] + string(q * 6, '9');
    }
  }
};
