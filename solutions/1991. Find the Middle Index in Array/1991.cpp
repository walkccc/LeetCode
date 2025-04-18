class Solution {
 public:
  int findMiddleIndex(vector<int>& nums) {
    int prefix = 0;
    int suffix = accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0; i < nums.size(); ++i) {
      suffix -= nums[i];
      if (prefix == suffix)
        return i;
      prefix += nums[i];
    }

    return -1;
  }
};
