class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0;
    int lastZeroIndex = -1;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      if (nums[r] == 0) {
        l = lastZeroIndex + 1;
        lastZeroIndex = r;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
