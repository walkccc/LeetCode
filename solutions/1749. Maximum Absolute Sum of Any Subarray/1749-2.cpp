class Solution {
 public:
  int maxAbsoluteSum(vector<int>& nums) {
    int sum = 0;
    int maxPrefix = 0;
    int minPrefix = 0;

    for (const int num : nums) {
      sum += num;
      maxPrefix = max(maxPrefix, sum);
      minPrefix = min(minPrefix, sum);
    }

    return maxPrefix - minPrefix;
  }
};
