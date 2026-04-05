class Solution {
 public:
  int superPow(int a, vector<int>& b) {
    int ans = 1;

    a %= kMod;
    for (const int i : b)
      ans = modPow(ans, 10) * modPow(a, i) % kMod;

    return ans;
  }

 private:
  static constexpr int kMod = 1337;

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
