class Solution {
 public:
  long long maximumSum(vector<int>& nums) {
    long long ans = 0;
    unordered_map<int, long long> oddPowerToSum;

    for (int i = 0; i < nums.size(); ++i) {
      const int oddPower = divideSquares(i + 1);
      ans = max(ans, oddPowerToSum[oddPower] += nums[i]);
    }

    return ans;
  }

 private:
  int divideSquares(int val) {
    for (int num = 2; num * num <= val; ++num)
      while (val % (num * num) == 0)
        val /= num * num;
    return val;
  }
};
