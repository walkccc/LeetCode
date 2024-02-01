class Solution {
 public:
  string smallestNumber(long long n) {
    if (n <= 9)
      return to_string(n);

    string ans;

    for (int divisor = 9; divisor > 1; --divisor)
      while (n % divisor == 0) {
        ans += to_string(divisor);
        n /= divisor;
      }

    return n > 1 ? "-1" : string{ans.rbegin(), ans.rend()};
  }
};
