class Solution {
 public:
  bool hasSameDigits(const string& s) {
    const int n = s.length();
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i + 1 < n; ++i) {
      const int coefficient = nCkMod10(n - 2, i);
      num1 += (coefficient * (s[i] - '0')) % 10;
      num1 %= 10;
      num2 += (coefficient * (s[i + 1] - '0')) % 10;
      num2 %= 10;
    }

    return num1 == num2;
  }

 private:
  // Returns (n, k) % 10.
  int nCkMod10(int n, int k) {
    const int mod2 = lucasTheorem(n, k, 2);
    const int mod5 = lucasTheorem(n, k, 5);
    static constexpr int lookup[2][5] = {
        {0, 6, 2, 8, 4},  // mod2 == 0
        {5, 1, 7, 3, 9}   // mod2 == 1
    };
    return lookup[mod2][mod5];
  }

  // Returns (n, k) % prime.
  int lucasTheorem(int n, int k, int prime) {
    int res = 1;
    while (n > 0 || k > 0) {
      const int nMod = n % prime;
      const int kMod = k % prime;
      res *= nCk(nMod, kMod);
      res %= prime;
      n /= prime;
      k /= prime;
    }
    return res;
  }

  // Returns (n, k).
  int nCk(int n, int k) {
    int res = 1;
    for (int i = 0; i < k; ++i) {
      res *= (n - i);
      res /= (i + 1);
    }
    return res;
  }
};
