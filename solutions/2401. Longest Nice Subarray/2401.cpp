class Solution {
 public:
  int longestNiceSubarray(vector<int>& nums) {
    int ans = 0;
    int usedBits = 0;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      while (usedBits & nums[r])
        usedBits ^= nums[l++];
      usedBits |= nums[r];
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
