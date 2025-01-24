class Solution {
 public:
  int maxLength(const vector<int>& nums) {
    constexpr int kMaxLcm = 36'288'000;  // 10! x 10
    const int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      int prod = 1;
      int l = 1;
      int g = 0;
      for (int j = i; j < n; ++j) {
        prod *= nums[j];
        if (prod > kMaxLcm)
          break;
        l = lcm(l, nums[j]);
        g = gcd(g, nums[j]);
        if (prod == l * g)
          ans = max(ans, j - i + 1);
      }
    }

    return ans;
  }
};
