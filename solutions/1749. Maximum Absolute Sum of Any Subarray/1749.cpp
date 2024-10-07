class Solution {
 public:
  int maxAbsoluteSum(vector<int>& nums) {
    int ans = INT_MIN;
    int maxSum = 0;
    int minSum = 0;

    for (const int num : nums) {
      maxSum = max(num, maxSum + num);
      minSum = min(num, minSum + num);
      ans = max({ans, maxSum, -minSum});
    }

    return ans;
  }
};
