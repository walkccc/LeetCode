class Solution {
 public:
  int makeArrayPositive(vector<int>& nums) {
    constexpr long kMax = 1'000'000'000'000'000'000;
    int ans = 0;
    long minSum = nums[0] + nums[1];
    vector<long> bigNums{nums.begin(), nums.end()};

    for (int i = 2; i < bigNums.size(); ++i) {
      const long a = bigNums[i - 2];
      const long b = bigNums[i - 1];
      const long c = bigNums[i];
      minSum = min(minSum + c, a + b + c);
      if (minSum <= 0) {
        bigNums[i] = kMax;
        minSum = kMax;
        ++ans;
      }
    }

    return ans;
  }
};
