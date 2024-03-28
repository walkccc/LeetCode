class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int l = 0;
    int count0 = 0;

    for (const int num : nums) {
      if (num == 0)
        ++count0;
      if (count0 > 1 && nums[l++] == 0)
        --count0;
    }

    return nums.size() - l - 1;
  }
};
