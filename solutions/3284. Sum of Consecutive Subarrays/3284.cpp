class Solution {
 public:
  int getSum(const std::vector<int>& nums) {
    const long sum = accumulate(nums.begin(), nums.end(), 0L) % kMod;
    return (getSum(nums, 1) + getSum(nums, -1) - sum) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns the sum of all subarrays with a difference of `diff`.
  long getSum(const vector<int>& nums, int diff) {
    long res = nums[0];
    long summ = nums[0];
    long count = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1] + diff) {
        count += 1;
        summ += count * nums[i];
      } else {
        count = 1;
        summ = nums[i];
      }
      res += summ;
      res %= kMod;
    }
    return res;
  };
};
