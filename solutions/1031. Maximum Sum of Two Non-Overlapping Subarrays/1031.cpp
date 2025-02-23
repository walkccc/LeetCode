class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    return max(helper(nums, firstLen, secondLen),
               helper(nums, secondLen, firstLen));
  }

 private:
  int helper(vector<int>& nums, int l, int r) {
    const int n = nums.size();
    vector<int> left(n);
    int sum = 0;

    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      if (i >= l)
        sum -= nums[i - l];
      if (i >= l - 1)
        left[i] = i > 0 ? max(left[i - 1], sum) : sum;
    }

    vector<int> right(n);
    sum = 0;

    for (int i = n - 1; i >= 0; --i) {
      sum += nums[i];
      if (i <= n - r - 1)
        sum -= nums[i + r];
      if (i <= n - r)
        right[i] = i < n - 1 ? max(right[i + 1], sum) : sum;
    }

    int ans = 0;

    for (int i = 0; i < n - 1; ++i)
      ans = max(ans, left[i] + right[i + 1]);

    return ans;
  }
};
