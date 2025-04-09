class Solution {
 public:
  long long sumDigitDifferences(vector<int>& nums) {
    const int n = nums.size();
    const int digitSize = std::to_string(nums[0]).size();
    long ans = 0;

    for (int i = 0, denominator = 1; i < digitSize; ++i, denominator *= 10) {
      vector<int> count(10);
      for (const int num : nums)
        ++count[num / denominator % 10];
      for (const int freq : count)
        ans += freq * (n - freq);
    }

    return ans / 2;
  }
};
