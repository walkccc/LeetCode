class Solution {
 public:
  bool judgePoint24(vector<int>& nums) {
    vector<double> doubleNums;

    for (const int num : nums)
      doubleNums.push_back(num);

    return dfs(doubleNums);
  }

 private:
  bool dfs(vector<double>& nums) {
    if (nums.size() == 1)
      return abs(nums[0] - 24) < 0.001;

    for (int i = 0; i < nums.size(); ++i)
      for (int j = 0; j < i; ++j) {
        for (const double num : generate(nums[i], nums[j])) {
          vector<double> nextRound{num};
          for (int k = 0; k < nums.size(); ++k) {
            if (k == i || k == j)  // It is used in `generate()`.
              continue;
            nextRound.push_back(nums[k]);
          }
          if (dfs(nextRound))
            return true;
        }
      }

    return false;
  }

  vector<double> generate(double a, double b) {
    return {a * b, a / b, b / a, a + b, a - b, b - a};
  }
};
