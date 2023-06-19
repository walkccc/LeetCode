class Solution {
 public:
  int minimumAverageDifference(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;
    int minDiff = INT_MAX;
    long prefix = 0;
    long suffix = accumulate(nums.begin(), nums.end(), 0L);

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      suffix -= nums[i];
      const int prefixAvg = prefix / (i + 1);
      const int suffixAvg = (i == n - 1) ? 0 : suffix / (n - i - 1);
      const int diff = abs(prefixAvg - suffixAvg);
      if (diff < minDiff) {
        ans = i;
        minDiff = diff;
      }
    }

    return ans;
  }
};
