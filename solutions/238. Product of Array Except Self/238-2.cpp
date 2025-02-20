class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n, 1);

    // Use ans as the prefix product array.
    for (int i = 1; i < n; ++i)
      ans[i] = ans[i - 1] * nums[i - 1];

    int suffix = 1;  // suffix product
    for (int i = n - 1; i >= 0; --i) {
      ans[i] *= suffix;
      suffix *= nums[i];
    }

    return ans;
  }
};
