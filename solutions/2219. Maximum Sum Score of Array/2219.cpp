class Solution {
 public:
  long long maximumSumScore(vector<int>& nums) {
    long long ans = LLONG_MIN;
    long long prefix = 0;
    long long sum = accumulate(begin(nums), end(nums), 0LL);

    for (const int num : nums) {
      prefix += num;
      ans = max({ans, prefix, sum - prefix + num});
    }

    return ans;
  }
};
