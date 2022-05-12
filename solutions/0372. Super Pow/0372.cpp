class Solution {
 public:
  int superPow(int a, vector<int>& b) {
    constexpr int k = 1337;
    int ans = 1;

    auto powMod = [&](int x, int y) {  // x^y % k
      int pow = 1;
      while (y--)
        pow = (pow * x) % k;
      return pow;
    };

    a %= k;
    for (const int i : b)
      ans = powMod(ans, 10) * powMod(a, i) % k;

    return ans;
  }
};
