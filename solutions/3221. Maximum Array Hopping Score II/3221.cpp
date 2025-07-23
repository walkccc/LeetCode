class Solution {
 public:
  // Same as 3205. Maximum Array Hopping Score I
  long long maxScore(vector<int>& nums) {
    // The optimal jump is the maximum number in the remaining suffix.
    long ans = 0;
    int mx = 0;

    for (int i = nums.size() - 1; i > 0; --i) {
      mx = max(mx, nums[i]);
      ans += mx;
    }

    return ans;
  }
};
