class Solution {
 public:
  // Similar to 3205. Maximum Array Hopping Score I
  long long findMaximumScore(vector<int>& nums) {
    // The optimal jump is the nearest index j > i s.t. nums[j] > nums[i].
    long ans = 0;
    int mx = 0;

    for (const int num : nums) {
      ans += mx;
      mx = max(mx, num);
    }

    return ans;
  }
};
