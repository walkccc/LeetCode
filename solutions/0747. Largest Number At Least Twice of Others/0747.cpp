class Solution {
 public:
  int dominantIndex(vector<int>& nums) {
    int ans;
    int max = 0;
    int secondMax = 0;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] > max) {
        secondMax = max;
        max = nums[i];
        ans = i;
      } else if (nums[i] > secondMax) {
        secondMax = nums[i];
      }

    return max >= 2 * secondMax ? ans : -1;
  }
};
