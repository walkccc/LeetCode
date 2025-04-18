class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int sum = 0;
    int minSum = 0;

    for (const int num : nums)
      minSum = min(minSum, sum += num);

    return 1 - minSum;
  }
};
