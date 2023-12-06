class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;
    long dp0 = 0;
    long dp1 = 0;

    for (const int a : arr) {
      if (a % 2 == 1) {
        const int cache = dp0;
        dp0 = dp1;
        dp1 = cache + 1;
      } else {
        ++dp0;
      }
      ans = (ans + dp1) % kMod;
    }

    return ans;
  }
};
