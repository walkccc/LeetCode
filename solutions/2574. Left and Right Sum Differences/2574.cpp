class Solution {
 public:
  vector<int> leftRigthDifference(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n);
    vector<int> leftSum(n);
    vector<int> rightSum(n);
    int prefix = 0;
    int suffix = 0;

    for (int i = 0; i < n; ++i) {
      if (i > 0)
        prefix += nums[i - 1];
      leftSum[i] = prefix;
    }

    for (int i = n - 1; i >= 0; --i) {
      if (i + 1 < n)
        suffix += nums[i + 1];
      rightSum[i] = suffix;
    }

    for (int i = 0; i < n; ++i)
      ans[i] = abs(leftSum[i] - rightSum[i]);

    return ans;
  }
};
