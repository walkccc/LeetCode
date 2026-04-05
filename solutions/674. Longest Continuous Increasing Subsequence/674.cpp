class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int ans = 0;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      if (r > 0 && nums[r] <= nums[r - 1])
        l = r;
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
