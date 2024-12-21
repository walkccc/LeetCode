class Solution {
 public:
  long long maximumSum(vector<int>& nums) {
    long ans = 0;

    for (int oddPower = 1; oddPower <= nums.size(); ++oddPower) {
      long sum = 0;
      for (int num = 1; num * num * oddPower <= nums.size(); ++num)
        sum += nums[oddPower * num * num - 1];
      ans = max(ans, sum);
    }

    return ans;
  }
};
