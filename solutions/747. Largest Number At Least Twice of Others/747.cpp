class Solution {
 public:
  int dominantIndex(vector<int>& nums) {
    int ans;
    int mx = 0;
    int secondMax = 0;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] > mx) {
        secondMax = mx;
        mx = nums[i];
        ans = i;
      } else if (nums[i] > secondMax) {
        secondMax = nums[i];
      }

    return mx >= 2 * secondMax ? ans : -1;
  }
};
