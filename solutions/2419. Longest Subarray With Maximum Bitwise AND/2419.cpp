class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int ans = 0;
    int maxIndex = 0;
    int sameNumLength = 0;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == nums[maxIndex]) {
        ans = max(ans, ++sameNumLength);
      } else if (nums[i] > nums[maxIndex]) {
        maxIndex = i;
        sameNumLength = 1;
        ans = 1;
      } else {
        sameNumLength = 0;
      }

    return ans;
  }
};
