class Solution {
 public:
  int countOrders(int n) {
    constexpr int kMod = 1'000'000'007;
    long ans = 1;

    for (int i = 1; i <= n; ++i)
      ans = ans * i * (i * 2 - 1) % kMod;

    return ans;
  }
};
