class Solution {
 public:
  int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    const int minNum = ranges::min(nums);
    const int maxNum = ranges::max(nums);
    const long sum = accumulate(nums.begin(), nums.end(), 0L);
    long ans = LONG_MAX;

    if (cost1 * 2 <= cost2 || n < 3) {
      const long totalGap = static_cast<long>(maxNum) * n - sum;
      return (cost1 * totalGap) % kMod;
    }

    for (int target = maxNum; target < 2 * maxNum; ++target) {
      const int maxGap = target - minNum;
      const long totalGap = static_cast<long>(target) * n - sum;
      const long pairs = min(totalGap / 2, totalGap - maxGap);
      ans = min(ans, cost1 * (totalGap - 2 * pairs) + cost2 * pairs);
    }

    return ans % kMod;
  }
};
