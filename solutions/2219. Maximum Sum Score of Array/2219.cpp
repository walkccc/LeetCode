class Solution {
 public:
  long long maximumSumScore(vector<int>& nums) {
    long ans = LONG_MIN;
    long prefix = 0;
    long sum = accumulate(nums.begin(), nums.end(), 0L);

    for (const int num : nums) {
      prefix += num;
      ans = max({ans, prefix, sum - prefix + num});
    }

    return ans;
  }
};
