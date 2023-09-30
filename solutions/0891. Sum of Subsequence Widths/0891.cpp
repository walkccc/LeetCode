class Solution {
 public:
  int sumSubseqWidths(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    long ans = 0;
    long exp = 1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i, exp = exp * 2 % kMod) {
      ans += (nums[i] - nums[n - i - 1]) * exp;
      ans %= kMod;
    }

    return ans;
  }
};
