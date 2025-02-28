class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    return numSubarraysWithSumAtMost(nums, goal) -
           numSubarraysWithSumAtMost(nums, goal - 1);
  }

 private:
  int numSubarraysWithSumAtMost(const vector<int>& nums, int goal) {
    int res = 0;
    int count = 0;
    for (int l = 0, r = 0; r < nums.size();) {
      count += nums[r++];
      while (l < r && count > goal)
        count -= nums[l++];
      // nums[l..r), nums[l + 1..r), ..., nums[r - 1]
      res += r - l;
    }
    return res;
  }
};
