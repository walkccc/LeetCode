class Solution {
 public:
  int countDigitOne(int n) {
    if (n < 0) return 0;

    int ans = 0;
    int num = n;

    for (long i = 1; i <= n; i *= 10, num /= 10) {
      const int prefix = n / (i * 10);
      const int suffix = n % i;
      const int currentDigit = num % 10;
      ans += prefix * i;
      if (currentDigit > 1)
        ans += i;
      else if (currentDigit == 1)
        ans += suffix + 1;
    }

    return ans;
  }
};