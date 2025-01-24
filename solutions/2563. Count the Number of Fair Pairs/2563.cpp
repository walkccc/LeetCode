class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    // nums[i] + nums[j] == nums[j] + nums[i], so the condition that i < j
    // degrades to i != j and we can sort the array.
    ranges::sort(nums);
    return countLess(nums, upper) - countLess(nums, lower - 1);
  }

 private:
  long countLess(const vector<int>& nums, int sum) {
    long res = 0;
    for (int i = 0, j = nums.size() - 1; i < j; ++i) {
      while (i < j && nums[i] + nums[j] > sum)
        --j;
      res += j - i;
    }
    return res;
  }
};
