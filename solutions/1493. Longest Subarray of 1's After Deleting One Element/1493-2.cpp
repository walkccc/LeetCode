class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int l = 0;
    int zeros = 0;

    for (const int num : nums) {
      if (num == 0)
        ++zeros;
      if (zeros > 1 && nums[l++] == 0)
        --zeros;
    }

    return nums.size() - l - 1;
  }
};
