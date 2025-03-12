class Solution {
 public:
  int sumOfPower(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;
    long sum = 0;

    ranges::sort(nums);

    for (const int num : nums) {
      ans = (ans + (num + sum) * num % kMod * num % kMod) % kMod;
      sum = (sum * 2 + num) % kMod;
    }

    return ans;
  }
};
