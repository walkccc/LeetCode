class Solution {
 public:
  string smallestGoodBase(string n) {
    unsigned long long num = stoll(n);

    for (int m = log2(num); m >= 2; --m) {
      const int k = pow(num, 1.0 / m);
      unsigned long long sum = 1;
      unsigned long long prod = 1;
      for (int i = 0; i < m; ++i) {
        prod *= k;
        sum += prod;
      }
      if (sum == num) return to_string(k);
    }

    return to_string(num - 1);
  }
};