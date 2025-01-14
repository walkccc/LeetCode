class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0;
    int currMaxSum = 0;
    int currMinSum = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;

    for (const int num : nums) {
      totalSum += num;
      currMaxSum = max(currMaxSum + num, num);
      currMinSum = min(currMinSum + num, num);
      maxSum = max(maxSum, currMaxSum);
      minSum = min(minSum, currMinSum);
    }

    return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
  }
};
