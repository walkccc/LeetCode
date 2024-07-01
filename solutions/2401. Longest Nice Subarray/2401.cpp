class Solution {
 public:
  int longestNiceSubarray(vector<int>& nums) {
    int ans = 0;
    int used = 0;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      while (used & nums[r])
        used ^= nums[l++];
      used |= nums[r];
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
