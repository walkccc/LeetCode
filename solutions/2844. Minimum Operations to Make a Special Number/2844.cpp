class Solution {
 public:
  int minimumOperations(string num) {
    const int n = num.length();
    bool seenFive = false;
    bool seenZero = false;

    for (int i = n - 1; i >= 0; --i) {
      if (seenZero && num[i] == '0')  // '00'
        return n - i - 2;
      if (seenZero && num[i] == '5')  // '50'
        return n - i - 2;
      if (seenFive && num[i] == '2')  // '25'
        return n - i - 2;
      if (seenFive && num[i] == '7')  // '75'
        return n - i - 2;
      seenZero = seenZero || num[i] == '0';
      seenFive = seenFive || num[i] == '5';
    }

    return seenZero ? n - 1 : n;
  }
};
