class Solution {
 public:
  int minimizeArrayValue(vector<int>& nums) {
    long ans = 0;
    long prefix = 0;

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      const long prefixAvg = ceil(prefix / static_cast<double>(i + 1));
      ans = max(ans, prefixAvg);
    }

    return ans;
  }
};
