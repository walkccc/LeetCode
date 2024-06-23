class Solution {
 public:
  int kthSmallestSubarraySum(vector<int>& nums, int k) {
    int l = 0;
    int r = accumulate(nums.begin(), nums.end(), 0);

    while (l < r) {
      const int m = (l + r) / 2;
      if (numSubarrayLessThan(nums, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int numSubarrayLessThan(const vector<int>& nums, int m) {
    int res = 0;
    int sum = 0;
    for (int l = 0, r = 0; r < nums.size(); ++r) {
      sum += nums[r];
      while (sum > m)
        sum -= nums[l++];
      res += r - l + 1;
    }
    return res;
  }
};
