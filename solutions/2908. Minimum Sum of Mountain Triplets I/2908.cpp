class Solution {
 public:
  int minimumSum(vector<int>& nums) {
    const int n = nums.size();
    int ans = INT_MAX;
    vector<int> minPrefix(n);
    vector<int> minSuffix(n);

    partial_sum(nums.begin(), nums.end(), minPrefix.begin(),
                [](int x, int y) { return min(x, y); });
    partial_sum(nums.rbegin(), nums.rend(), minSuffix.begin(),
                [](int x, int y) { return min(x, y); });
    reverse(minSuffix.begin(), minSuffix.end());

    for (int i = 0; i < n; ++i)
      if (nums[i] > minPrefix[i] && nums[i] > minSuffix[i])
        ans = min(ans, nums[i] + minPrefix[i] + minSuffix[i]);

    return ans == INT_MAX ? -1 : ans;
  }
};
