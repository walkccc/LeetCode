class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    constexpr int kMax = 9 * 9;  // 999,999,999
    int ans = -1;
    vector<vector<int>> count(kMax + 1);

    for (const int num : nums)
      count[getSum(num)].push_back(num);

    for (auto& groupNums : count) {
      if (groupNums.size() < 2)
        continue;
      sort(begin(groupNums), end(groupNums), greater<>());
      ans = max(ans, groupNums[0] + groupNums[1]);
    }

    return ans;
  }

 private:
  int getSum(int num) {
    int sum = 0;
    while (num) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
};
