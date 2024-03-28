class Solution {
 public:
  long long makeIntegerBeautiful(long long n, int target) {
    long long ans = 0;
    long power = 1;

    // e.g. n = 123. After tunning off the last bit by adding 7, n = 130.
    // Effectively, we can think n as 13. That's why we do n = (n / 10) + 1.
    while (sum(n) > target) {
      // the cost to turn off the last digit
      ans += power * (10 - n % 10);
      n = n / 10 + 1;
      power *= 10;
    }

    return ans;
  }

 private:
  int sum(long long n) {
    int res = 0;
    while (n > 0) {
      res += n % 10;
      n /= 10;
    }
    return res;
  }
};
