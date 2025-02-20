class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    const int n = nums.size();
    const int size = 2 * k + 1;
    vector<int> ans(n, -1);
    if (size > n)
      return ans;

    long sum = accumulate(nums.begin(), nums.begin() + size, 0L);

    for (int i = k; i + k < n; ++i) {
      ans[i] = sum / size;
      if (i + k + 1 < n)
        sum += nums[i + k + 1] - nums[i - k];
    }

    return ans;
  }
};
