class Solution {
 public:
  int countValidSelections(vector<int>& nums) {
    int ans = 0;
    int prefix = 0;
    int suffix = accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < nums.size(); ++i) {
      suffix -= nums[i];
      prefix += nums[i];
      if (nums[i] > 0)
        continue;
      if (prefix == suffix)
        ans += 2;  // Go to either direction.
      if (abs(prefix - suffix) == 1)
        ans += 1;  // Go to the direction with the larger sum.
    }

    return ans;
  }
};
