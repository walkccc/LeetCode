class Solution {
 public:
  int maximumSum(vector<int>& nums) {
    constexpr int kMax = 9 * 9;  // 999,999,999
    int ans = -1;
    vector<vector<int>> count(kMax + 1);

    for (const int num : nums)
      count[getSum(num)].push_back(num);

    for (vector<int>& groupNums : count) {
      if (groupNums.size() < 2)
        continue;
      ranges::sort(groupNums, greater<>());
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
