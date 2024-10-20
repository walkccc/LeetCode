class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ans = INT_MIN;
    int sum = 0;

    for (const int num : nums) {
      sum = max(num, sum + num);
      ans = max(ans, sum);
    }

    return ans;
  }
};
