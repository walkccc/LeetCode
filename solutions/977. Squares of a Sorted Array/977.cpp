class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n);
    int i = n - 1;

    for (int l = 0, r = n - 1; l <= r;)
      if (abs(nums[l]) > abs(nums[r]))
        ans[i--] = nums[l] * nums[l++];
      else
        ans[i--] = nums[r] * nums[r--];

    return ans;
  }
};
