class Solution {
 public:
  int maximizeGreatness(vector<int>& nums) {
    int ans = 0;

    ranges::sort(nums);

    for (const int num : nums)
      if (num > nums[ans])
        ++ans;

    return ans;
  }
};
