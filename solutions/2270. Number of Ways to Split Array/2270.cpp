class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    int ans = 0;
    long prefix = 0;
    long suffix = accumulate(begin(nums), end(nums), 0L);

    for (int i = 0; i < nums.size() - 1; ++i) {
      prefix += nums[i];
      suffix -= nums[i];
      if (prefix >= suffix)
        ++ans;
    }

    return ans;
  }
};
